/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:37:42 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 02:20:00 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_child(t_term *term, t_parsing *cmd, int last_child)
{
	int	built;

	redir_flux(cmd, last_child);
	g_err = 0;
	built = ft_exec_builtin(term, cmd, 0, 0);
	if (built <= 0)
	{
		ft_close(cmd->in, cmd->out);
		ft_free_term(term);
		ft_free_pars(cmd);
	}
	if (built < 0)
		exit(EXIT_FAILURE);
	else if (!built)
	{
		exit(EXIT_SUCCESS);
	}
	ft_close_exec(cmd);
	execve(cmd->path, cmd->argv, term->env);
	perror(MINISHELL);
	g_err = 1;
	ft_free_term(term);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}

int	ft_exec_builtin(t_term *term, t_parsing *parsing, int exec, t_cmd *cmd)
{
	int	i;

	i = ft_is_builtin(parsing->argv[0]);
	if ((i >= 0 && i < 3) && exec)
	{
		if (!cmd)
			return (term->built[i](term, parsing));
		else
			return (0);
	}
	if (i >= 3 && i <= 5 && !exec)
		return (term->built[i](term, parsing));
	return (1);
}

int	ft_exec(t_term *term, t_parsing *cmd)
{
	int	child;
	int	last_child;

	last_child = 0;
	child = fork();
	if (child < 0)
		return (0);
	signal_handler_child(child);
	if (child == 0)
		ft_child(term, cmd, last_child);
	ft_close(cmd->in, cmd->out);
	ft_close(cmd->pipe_out[1], 0);
	signal_handler();
	last_child = child;
	return (0);
}

int	ft_select_built_exec(t_term *term,
	t_parsing *exec, int in_pipe, t_cmd *next)
{
	int	i;

	i = ft_is_builtin(exec->argv[0]);
	if (i >= 0 && i <= 3)
		ft_exec_builtin(term, exec, 1, next);
	else
	{
		ft_exec(term, exec);
		return (1);
	}
	return (0);
}

int	exec(t_term *term, t_cmd **tab)
{
	t_parsing	*exec;
	int			pipefd[2];

	(void)term;
	pipefd[0] = 0;
	pipefd[1] = 0;
	exec = 0;
	printf("exec\n");
	ft_launch_exec(term, &exec, pipefd, tab);
	return (0);
}
