/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:39:29 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 17:08:36 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_make_cmd(char *str, t_cmd **cmd)
{
	t_cmd	*new;

	if (str)
	{
		new = ft_init_cmd();
		if (!new)
			return (-1);
		new->arg = ft_strdup(str);
		if (!new->arg)
		{
			free(new);
			return (-1);
		}
		*cmd = new;
	}
	return (0);
}

void	ft_print_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		printf("cmd:%s|%d|first:%d|\n", cmd->arg, cmd->flag, cmd->first);
		cmd = cmd->next;
	}
	return ;
}

void	ft_print_tab_cmd(t_cmd **tab)
{
	int	l;

	l = 0;
	while (tab && tab[l])
	{
		printf("=======cmd=======\n");
		ft_print_cmd(tab[l]);
		l++;
	}
}
