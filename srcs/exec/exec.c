/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:19:33 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/04 15:48:13 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_pipe(t_parsing *cmd)
{
	if (cmd->in  > 1)
		close(cmd->in);
	if (cmd->out > 1)
		close(cmd->out);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}

void	ft_close(int fd1, int fd2)
{
	if (fd1 > 1)
		close(fd1);
	if (fd2 > 1)
		close(fd2);
}

int	ft_child(t_term *term, t_parsing *cmd, int last_child)
{
	int	status;

	redir_flux(cmd, last_child);
	status = ft_exec_builtin(term, cmd, 0);
	if (status <= 0)
	{
		ft_close(cmd->in, cmd->out);
		ft_free_term(term);
		ft_free_pars(cmd);
	}
	if (status < 0)
		exit(EXIT_FAILURE);
	else if (!status)
	{
		exit(EXIT_SUCCESS);
	}
	ft_close(cmd->in, cmd->out);
	execve(cmd->path, cmd->argv, term->env);
	perror("ERROR:\n");
	ft_free_term(term);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}

int	ft_exec_builtin(t_term *term, t_parsing *parsing, int exec)
{
	int	i;

	i = ft_is_builtin(parsing->argv[0]);
	if (i >= 0 && i < 3 && exec)
		return (term->built[i](term, parsing));
	if (i >= 3 && i <= 5 && !exec)
		return (term->built[i](term, parsing));
	return (1);
}

int	exec(t_term *term, t_parsing *cmd)
{
	int				child;
	int				status;
	int				last_child;

	last_child = 0;
	while (cmd) 
	{
		if ((cmd->path || (cmd->argv && cmd->argv[0] && (ft_is_builtin(cmd->argv[0]) >= 0))) && !ft_setflux(cmd))
		{
			if (ft_exec_builtin(term, cmd, 1) == 1)
			{
				child = fork();
				if (child < 0)
					return (0);
				else if (child == 0)
					ft_child(term, cmd, last_child);
				ft_close(cmd->in, cmd->out);
				status = 0;
				waitpid(0, &status, 0);
				last_child = child;
			}
		}
		else
			perror(cmd->argv[0]);
		cmd = cmd->next;
	}
	return (0);
}
