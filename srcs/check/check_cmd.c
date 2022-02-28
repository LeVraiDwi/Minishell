/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:27:03 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 18:27:04 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
				ft_add_flag(cmd, ARG);
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
