/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:55:45 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/24 19:15:24 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_redir(t_cmd *cmd)
{
	t_cmd	*next;

	if ((cmd->flag & PIPE))
		return (-1);
	while (cmd)
	{
		next = (t_cmd *)cmd->next;
		if ((cmd->flag & IS_REDIR) && !(cmd->flag & IGNORE))
		{
			if (!next || next->flag & IS_SPE)
			{
				write(2, "erreur\n", 7);
			}
			if (next)
				ft_add_flag(next, IGNORE);
		}
		cmd = cmd->next;
	}
	return (0);
}

int	ft_is_cmd(t_cmd *cmd)
{
	int	flag;

	if (!cmd)
		return (0);
	flag = cmd->flag;
	if (!(flag & IGNORE))
	{
		if (!(flag & IS_REDIR) && !(flag & PIPE))
			return (1);
	}
	return (0);

}

int	ft_set_cmd(t_cmd *cmd)
{
	int	var;

	var = 0;
	while (cmd)
	{
		if (ft_is_cmd(cmd))
		{
			if (!var)
			{
				ft_add_flag(cmd, CMD);
				var = 1;
			}
			else
				ft_add_flag(cmd, ARG);
		}
		else if (cmd->flag & PIPE)
			var = 0;
		cmd = cmd->next;
	}
	return (0);
}

int	ft_check_file(t_cmd *cmd)
{
	t_cmd	*next;

	next = (t_cmd *)cmd->next;
	if (access(next->arg, F_OK) == 0)
	{
		if (ft_isdir(next->arg) < 0)
			return (-1);
		if (cmd->flag & SIMPLE_REDIR_IN)
			if (access(cmd->arg, R_OK) < 0)
				return (-1);
		if ((cmd->flag & SIMPLE_REDIR_OUT) || (cmd->flag & DOUBLE_REDIR_OUT))
			if (access(cmd->arg, R_OK | W_OK) < 0)
				return (-1);
	}
	else
		if (cmd->flag & SIMPLE_REDIR_IN)
			return (-1);
	return (0);
}

int	check_file(t_cmd *cmd)
{
	while (cmd)
	{
		if ((cmd->flag & IS_REDIR) && !(cmd->flag & DOUBLE_REDIR_IN) && !(cmd->flag & IGNORE))
		{
			if (!ft_check_file(cmd))
				return (-1);
		}
		cmd = cmd->next;
	}
	return(0);
}
