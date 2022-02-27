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
	if (cmd->in >= 0)
		close(cmd->in);
	if (cmd->out >= 0)
		close(cmd->out);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
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
	ft_close_exec(cmd);
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

void	signal_handler_child()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	ft_exec(t_term *term, t_parsing *cmd)
{
	int	status;
	int	child;
	int	last_child;

	last_child  = 0;
	if (ft_exec_builtin(term, cmd, 1) == 1)
	{
		child = fork();
		if (child < 0)
			return (0);
		else if (child == 0)
		ft_child(term, cmd, last_child);
		ft_close(cmd->in, cmd->out);
		status = 0;
		signal_handler_child();
		waitpid(0, &status, 0);
		signal_handler();
		last_child = child;
	}
	return (0);
}

int	exec(t_term *term, t_cmd **tab)
{
	t_parsing	*exec;
	int			i;
	int			l;
	int			pipefd[2];

	(void)term;
	i = 0;
	pipefd[0] = 0;
	pipefd[1] = 0;
	while (tab[i])
	{
		exec = 0;
		if (creat_exec(term, tab[i], &exec, pipefd) == 0)
		{
			l = 0;
			while (exec->argv[l])
			{
				l++;
			}
			if (tab[i + 1])
				ft_init_pipe_out(exec, pipefd);
			ft_select_std(exec, tab[i + 1]);
			l = 0;
			while (exec->argv[l])
			{
				l++;
			}
			ft_exec(term, exec);
		}
		else if (tab[i + 1])
			ft_init_pipe_out(exec, pipefd);
		ft_free_pars(exec);
		i++;
	}
	return (0);
}
