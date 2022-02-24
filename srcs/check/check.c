/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:55:45 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/24 20:55:09 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_redir(t_cmd *cmd)
{
	t_cmd	*next;
	t_cmd	*first;

	first = cmd;
	if ((cmd->flag & PIPE))
				return (ft_set_err(cmd, first, SYNTAX_ERR));
	while (cmd)
	{
		next = (t_cmd *)cmd->next;
		if ((cmd->flag & IS_REDIR) && !(cmd->flag & IGNORE))
		{
			if (next)
				ft_add_flag(next, IGNORE);
			if (!next || next->flag & IS_SPE)
				return (ft_set_err(cmd, first, SYNTAX_ERR));
		}
		cmd = cmd->next;
	}
	return (0);
}

int	ft_check_pipe(t_cmd *cmd)
{
	t_cmd	*next;

	if ((cmd->flag & PIPE))
				return (ft_set_err(cmd, cmd, SYNTAX_ERR));
	while (cmd)
	{
		next = (t_cmd *)next;
		if ((cmd->flag & PIPE) && (next->flag & PIPE))
				return (ft_set_err(cmd, cmd, SYNTAX_ERR));
		cmd = cmd->next;
	}
	return (0);
}

int	ft_check_parsing(t_cmd **tab)
{
	int	l;

	l= 0;
	while (tab[l])
	{
		if (ft_check_redir(tab[l]) < 0)
			return (-1);
		l++;
	}
	return (0);
}
