/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:18:15 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 23:18:17 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_var_len(char *var)
{
	int	i;

	i = 0;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return (i);
}

t_cmd	*ft_next_cmd(t_cmd *cmd)
{
	if (cmd->next)
		return ((t_cmd *)(((t_cmd *)cmd->next)->next));
	else
		return (cmd->next);
}

int	split_spe_char(t_cmd *cmd)
{
	int	i;
	int	flag;

	while (cmd)
	{
		i = 0;
		while (cmd && cmd->arg && cmd->arg[i])
		{
			flag = ft_is_special_char(cmd->arg, i, cmd->flag);
			if (ft_split_quote_spe(cmd, flag, &i) < 0)
				return (-1);
			flag = 0;
			if (cmd->arg[i])
				i++;
		}
		cmd = cmd->next;
	}
	return (0);
}

int	ft_split_var(t_cmd **comd, int i)
{
	int		l;
	char	*tmp;
	t_cmd	*cmd;

	cmd = *comd;
	l = ft_var_len(cmd->arg + i + 1);
	if (l)
	{
		tmp = cmd->arg;
		if (ft_add_or_next(&cmd, tmp, i, l) < 0)
			return (ft_free((void **)&tmp));
		ft_add_flag(cmd, VAR);
		if (tmp[i + l + 1])
		{
			if (ft_set_new_cmd(cmd, tmp, i + l + 1,
					ft_strlen(tmp + i + l + 1)) < 0)
				return (ft_free((void **)&tmp));
		}
		free(tmp);
		*comd = cmd;
	}
	return (0);
}

int	ft_set_new_cmd(t_cmd *cmd, char *tmp, int start, int l)
{
	t_cmd	*new;

	new = ft_init_cmd();
	if (!new)
		return (-1);
	ft_add_next_cmd(cmd, new);
	new->arg = ft_substr(tmp, start, l);
	if (!new->arg)
		return (-1);
	ft_set_flag(cmd, new);
	return (0);
}
