/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:15:35 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 16:19:09 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_flux(t_parsing *cmd, int last_child)
{
	(void)last_child;
/*	int	status;

	status = 0;
	if (last_child != 0)
		waitpid(last_child, &status, 0);*/
	if (cmd->in != STDIN)
		if (dup2(cmd->in, STDIN) < 0)
			return (ft_error_pipe(cmd));
	if (cmd->out != STDOUT)
		if (dup2(cmd->out, STDOUT) < 0)
			return (ft_error_pipe(cmd));
	return (0);
}

int	ft_is_exit(t_parsing *exec)
{
	if (strisstr(exec->argv[0], "exit"))
	{	
		return (1);
	}
	return (0);
}

int	ft_launch_exec(t_term *term, t_parsing **exec, int *pipefd, t_cmd **tab)
{
	t_parsing	*new;
	int			i;
	int			nb_fork;
	int			in_pipe;

	i = 0;
	in_pipe = 0;
	if (tab[i + 1])
		in_pipe = 1;
	nb_fork = 0;
	while (tab[i])
	{
		if (creat_exec(term, tab[i], exec, pipefd) == 0)
		{
			new = ft_get_last_pars(*exec);
			ft_set_pipe(new, pipefd, tab[i + 1]);
			if (ft_is_exit(new))
			{
				if (!in_pipe)
					ft_exit(term, *exec, tab, new);
			}
			else
				nb_fork += ft_select_built_exec(term, new, in_pipe, tab[i + 1]);
		}
		i++;
	}
	ft_wait_child(nb_fork);
	return (0);
}

int	ft_set_pipe(t_parsing *exec, int *pipefd, t_cmd *next)
{
	if (exec->pipe_out[0] == 0 && exec->pipe_out[1] == 0)
	{
		if (pipe(exec->pipe_out) < 0)
			return (-1);
		ft_dup_pipe(exec->pipe_out, pipefd);
	}
	if (next)
	{
		if (!exec->out || exec->out == STD_OUT)
			exec->out = exec->pipe_out[1];
	}
	else
		if (!exec->out)
			exec->out = STD_OUT;
	return (0);
}

void	ft_wait_child(int nb_fork)
{
	int	status;

	while (nb_fork--)
	{
		status = 0;
		waitpid(0, &status, 0);
		set_status_err(status, 0);
	}
	signal_handler();

}
