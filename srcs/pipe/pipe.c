/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:51:46 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 17:52:10 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**ft_creat_tab(t_cmd *cmd)
{
	t_cmd	**tab;

	tab = (t_cmd **)malloc(sizeof(t_cmd *) * (2));
	if (!tab)
		return (0);
	tab[0] = cmd;
	tab[1] = 0;
	return (tab);
}

int	ft_split_pipe_cmd(t_cmd ***tab, t_cmd *cmd)
{
	while (cmd)
	{
		if (!(cmd->flag & IGNORE) && (cmd->flag & PIPE))
		{
			if (ft_split_tab(tab, cmd) < 0)
			{
				ft_free_cmd_tab(*tab);
				return (-1);
			}
			cmd->next = 0;
		}
		cmd = cmd->next;
	}
	return (0);
}

t_cmd	**split_pipe(t_cmd *cmd)
{
	t_cmd	**tab;
	t_cmd	*first;
	int		l;

	tab = ft_creat_tab(cmd);
	if (!tab)
	{
		ft_free_cmd(cmd);
		return (0);
	}
	first = cmd;
	l = 0;
	while (tab[l])
	{
		if (ft_split_pipe_cmd(&tab, cmd) < 0)
			return (0);
		l++;
		cmd = tab[l];
	}
	return (tab);
}

int	ft_split_tab(t_cmd ***tab, t_cmd *cmd)
{
	t_cmd	**tmp;
	int		l;

	l = 0;
	while ((*tab)[l])
		l++;
	tmp = (t_cmd **)malloc(sizeof(t_cmd *) * (l + 2));
	if (!tmp)
		return (-1);
	tmp[l + 1] = 0;
	l = 0;
	while ((*tab)[l])
	{
		tmp[l] = (*tab)[l];
		l++;
	}
	tmp[l] = new_pipe(cmd);
	free(*tab);
	*tab = tmp;
	return (0);
}

int	ft_free_cmd_tab(t_cmd **tab)
{
	int	l;

	l = 0;
	while (tab[l])
	{
		ft_free_cmd(tab[l]);
		tab[l] = 0;
		l++;
	}
	free(tab);
	return (-1);
}
