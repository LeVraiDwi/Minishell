/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:16:12 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 18:16:13 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_close_exec(t_parsing *exec)
{
	ft_close(exec->pipe_in[0], exec->pipe_in[1]);
	ft_close(exec->pipe_out[0], exec->pipe_out[1]);
	return (-1);
}

void	ft_dup_pipe(int *old, int *new)
{
	new[0] = old[0];
	new[1] = old[1];
}

int	ft_error_pipe(t_parsing *cmd)
{
	if (cmd->in >= 0)
		close(cmd->in);
	if (cmd->out >= 0)
		close(cmd->out);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}
