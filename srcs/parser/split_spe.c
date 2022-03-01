/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:46:37 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 22:23:15 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_flag(t_cmd *cmd, int flag)
{
	if (cmd && !(cmd->flag & flag))
		cmd->flag += flag;
}

int	ft_split_spe(t_cmd **comd, int start, int flag)
{
	int		l;
	char	*tmp;
	t_cmd	*cmd;

	l = ft_len_spe(flag);
	cmd = *comd;
	if (l)
	{
		tmp = cmd->arg;
		if (ft_add_or_next(&cmd, tmp, start, l - 1) < 0)
			return (ft_free((void **)&tmp));
		ft_add_flag(cmd, flag);
		if (tmp[start + l])
		{
			if (ft_set_new_cmd(cmd, tmp, start + l,
					ft_strlen(tmp + start + l)) < 0)
				return (ft_free((void **)&tmp));
		}
		free(tmp);
		*comd = cmd;
	}
	return (0);
}

int	ft_split_quote_spe(t_cmd *cmd, int flag, int *i)
{
	if (flag & VAR && !(cmd->flag & SIMPLE_QUOTE))
	{
		if (ft_split_var(&cmd, *i) < 0)
			return (-1);
	}
	else if (ft_is_interprete(cmd, flag))
	{
		if (ft_split_spe(&cmd, *i, flag) < 0)
			return (-1);
		*i = ft_strlen(cmd->arg);
	}
	return (0);
}

int	ft_add_or_next(t_cmd **comd, char *tmp, int i, int l)
{
	t_cmd	*cmd;

	cmd = *comd;
	cmd->arg = ft_substr(cmd->arg, 0, i);
	if (!cmd->arg)
		return (-1);
	if (*cmd->arg)
	{		
		if (ft_set_new_cmd(cmd, tmp, i, l + 1) < 0)
			return (-1);
		*comd = cmd->next;
	}
	else
	{
		if (cmd->arg)
			free(cmd->arg);
		cmd->arg = ft_substr(tmp, i, l + 1);
		if (!cmd->arg)
			return (-1);
	}
	return (0);
}

void	ft_set_flag(t_cmd *cmd, t_cmd *new)
{
	if (!(new->flag & JOIN))
		new->flag += JOIN;
	if ((cmd->flag & DOUBLE_QUOTE) && !(new->flag & DOUBLE_QUOTE))
		new->flag += DOUBLE_QUOTE;
	if ((cmd->flag & SIMPLE_QUOTE) && !(new->flag & SIMPLE_QUOTE))
		new->flag += SIMPLE_QUOTE;
}
