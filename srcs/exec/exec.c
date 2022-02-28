/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:37:42 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 18:24:04 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_child(t_term *term, t_parsing *cmd, int last_child)
{
	int	status;

	redir_flux(cmd, last_child);
	g_err = 0;
	status = ft_exec_builtin(term, cmd, 0, 0);
	if (status <= 0)
	{
		g_err = 1;
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
	if (((i >= 0 && i < 3) || (i == 6)) && exec)
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
	int	status;
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
	status = 0;
	errno = 0;
	waitpid(0, &status, 0);
	set_status_err(status, 0);
	signal_handler();
	last_child = child;
	return (0);
}

int	ft_select_built_exec(t_term *term, t_parsing *exec, t_cmd **tab, int i)
{
	int	ret;

	ft_select_std(exec, tab[i + 1]);
	ret = ft_exec_builtin(term, exec, 1, tab[i + 1]) == 1;
	if (ret == 1)
		ft_exec(term, exec);
	else if (ret < 0)
		ft_set_err(0, PERROR_ERR);
	else
		g_err = 0;
	return (0);
}

int	exec(t_term *term, t_cmd **tab)
{
	t_parsing	*exec;
	int			i;
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
			if (tab[i + 1])
				ft_init_pipe_out(exec, pipefd);
			ft_select_built_exec(term, exec, tab, i);
		}
		else if (tab[i + 1])
			ft_init_pipe_out(exec, pipefd);
		ft_free_pars(exec);
		i++;
	}
	return (0);
}
