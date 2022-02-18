/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:18:17 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 17:56:58 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_is_quote(char c)
{
	if (c == '\'')
		return ('\'');
	if (c == '\"')
		return ('\"');
	return (0);
}

int	ft_quote_len(char *str)
{
	int		i;
	char	c;
	char	tmp;

	i = 0;
	if (!str)
		return (-1);
	c = ft_is_quote(str[i]);
	if (c)
		i++;
	else
		return (-1);
	while (str[i])
	{
		tmp = ft_is_quote(str[i]);
		if (tmp == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_type_quote(char c, int flag)
{
	if (c == '\'' && !(flag & SIMPLE))
		return (SIMPLE);
	if (c == '\"' && !(flag & DOUBLE))
		return (DOUBLE);
	return (0);
}

int	ft_split_quote(t_cmd *cmd, int len_q, char type, int start)
{
	char	*tmp;
	t_cmd	*new;

	tmp = cmd->arg;
	cmd->arg = ft_substr(cmd->arg, 0, start);
	if (!tmp)
		return (ft_free((void **)&tmp));
	new = ft_init_cmd();
	if (!new)
		return (ft_free((void **)&tmp));
	ft_add_next_cmd(cmd, new);
	new->arg = ft_substr(tmp, start + 1, len_q - 1);
	if (!new->arg)
		return (ft_free((void **)&tmp));
	new->flag += JOIN;
	new->flag += ft_type_quote(type, cmd->flag);
	if (tmp[start + len_q + 2])
		if (ft_add_new_cmd(cmd, tmp, start, len_q) < 0)
			return (-1);
	return (0);
}

int	split_quote(t_cmd *quote)
{
	int		i;
	int		l;
	t_cmd	*cmd;

	cmd = quote;
	l = 0;
	while (cmd)
	{
		i = 0;
		while (l != -2 && cmd->arg[i])
		{
			if (ft_do_quote(&cmd, i, &l) < 0)
				return (-1);
			i++;
		}
		l = 0;
		cmd = cmd->next;
	}
	return (0);
}
