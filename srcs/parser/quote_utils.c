/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:03:50 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/21 18:45:11 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_new_cmd(t_cmd *cmd, char *str, int flag)
{
	t_cmd	*new;

	if (!str)
		return (-1);
	new = ft_init_cmd();
	if (!new)
		return (ft_free((void **)&str));
	ft_add_next_cmd(cmd, new);
	new->flag = flag;
	new->arg = ft_strdup(str);
	if (!new->arg)
		return (ft_free((void **)&str));
	free(str);
/*	new = ft_init_cmd();
	if (!new)
		return (ft_free((void **)&tmp));
	ft_add_next_cmd(cmd, new);
	new->flag = cmd->flag;
	if (!(new->flag & JOIN))
		new->flag += JOIN;
	new->arg = ft_substr(tmp, start + len_q
			+ 1, ft_strlen(tmp + start + len_q + 1));
	if (!new->arg)
		return (-1);*/
	return (1);
}

int	ft_do_quote(t_cmd **cmd, int i, int *l)
{
	int	flag;

	if (ft_is_quote((*cmd)->arg[i]))
	{
		if (((*cmd)->arg[i] == '\"' && !((*cmd)->flag & SIMPLE_QUOTE))
			|| ((*cmd)->arg[i] == '\'' && !((*cmd)->flag & DOUBLE_QUOTE)))
		{
			flag = (*cmd)->flag;
			*l = ft_quote_len((*cmd)->arg + i);
			if (*l >= 0)
			{
				if (ft_split_quote(cmd, ft_is_quote((*cmd)->arg[i]), i, flag))
					return (ft_free_cmd((*cmd)));
				*l = -2;
			}
		}
	}
	return (0);
}

int	ft_make_quote_flag(int old_flag, char type, int join, int first)
{
	int	flag;

	flag = old_flag;
	if (join && !(flag & JOIN) && !first)
		flag += JOIN;
	flag += ft_type_quote(type, flag);
	return (flag);
}	
