/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:55:45 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/23 19:59:54 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_redir(t_cmd *cmd)
{
	t_cmd	*next;

	while (cmd)
	{
		next = (t_cmd *)cmd->next;
		if ((cmd->flag & IS_REDIR) && !(cmd->flag & IGNORE))
		{
			if (!next || next->flag & IS_SPE)
			{
				printf("erreur\n");
			}
			if (next)
				ft_add_flag(next, IGNORE);
		}
		cmd = cmd->next;
	}
	return (1);
}
