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

int	ft_add_new_cmd(t_cmd *cmd, char *tmp, int start, int len_q)
{
	t_cmd	*new;

	new = ft_init_cmd();
	if (!new)
		return (ft_free((void **)&tmp));
	ft_add_next_cmd((t_cmd *)cmd->next, new);
	new->flag = cmd->flag;
	if (!(new->flag & JOIN))
		new->flag += JOIN;
	new->arg = ft_substr(tmp, start + len_q
			+ 1, ft_strlen(tmp + start + len_q + 1));
	free(tmp);
	if (!new->arg)
		return (-1);
	return (1);
}

int	ft_do_quote(t_cmd **cmd, int i, int *l)
{
	if (ft_is_quote((*cmd)->arg[i]))
	{
		if (((*cmd)->arg[i] == '\"' && !((*cmd)->flag & SIMPLE))
			|| ((*cmd)->arg[i] == '\'' && !((*cmd)->flag & DOUBLE)))
		{
			*l = ft_quote_len((*cmd)->arg + i);
			if (*l >= 0)
				if (ft_split_quote(*cmd, *l, ft_is_quote((*cmd)->arg[i]), i))
					return (ft_free_cmd((*cmd)));
			*l = -2;
		}
	}
	return (0);
}
