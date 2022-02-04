/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:19:33 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:45:44 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_pipe(t_parsing *cmd)
{
	if (cmd->in > 2)
		close(cmd->in);
	if (cmd->out > 2)
		close(cmd->out);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}

void ft_close_pipe(t_term *term, t_parsing *cmd)
{
	if (term->pipefd[0] != cmd->in)
		close(term->pipefd[0]);
	if (term->pipefd[1] != cmd->out)
		close(term->pipefd[1]);
}

int	ft_child(t_term *term, t_parsing *cmd, int last_child)
{
	int	status;

	status = 0;
	printf("child\n");
	if (last_child != 0)
		waitpid(last_child, &status, 0);
	if (dup2(cmd->in, STDIN) < 0)
		exit(ft_error_pipe(cmd));
	if (dup2(cmd->out, STDOUT) < 0)
		exit(ft_error_pipe(cmd));
	ft_close_pipe(term, cmd);
	printf("child\n");
	execve(cmd->path, cmd->argv, term->env);
	perror("ERROR:\n");
	//free_term(term);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}

int	ft_exec_builtin(t_term *term, t_parsing *parsing)
{
	int	i;

	i = ft_is_builtin(parsing->argv[0]);
	if (i > 0)
		return (term->built[i](term, parsing->argv));
	return (1);
}

int	exec(t_term *term, t_parsing *cmd)
{
	int				child;
	int				status;
	int				last_child;
	int				nb_child;

	nb_child = 0;
	last_child = 0;
	status = ft_exec_builtin(term, cmd);
	if (status < 0)
		return (-1);
	else if (!status)
		return (0);
	status = 0;
	while (cmd)
	{
		if (cmd->path)
		{
			child = fork();
			if (child < 0)
				return (0);
			else if (child == 0)
				ft_child(term, cmd, last_child);
			nb_child++;
			last_child = child;
		}
		cmd = cmd->next;
	}
	while (nb_child--)
	{
		if (waitpid(-1, &status, 0) < 0)
			exit(EXIT_FAILURE);
	}
	return (0);
}
