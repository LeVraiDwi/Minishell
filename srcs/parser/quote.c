/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:06:04 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/24 17:26:30 by tcosse           ###   ########.fr       */
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
	if (c == '\'' && !(flag & SIMPLE_QUOTE) && !(flag & DOUBLE_QUOTE))
		return (SIMPLE_QUOTE);
	if (c == '\"' && !(flag & DOUBLE_QUOTE) && !(flag & SIMPLE_QUOTE))
		return (DOUBLE_QUOTE);
	return (0);
}

int	ft_split_quote(t_cmd **comd, char type, int start, int flag)
{
	char	*tmp;
	char	*arg;
	t_cmd	*cmd;
	int		l;

	cmd = *comd;
	tmp = cmd->arg;
	l = ft_quote_len(cmd->arg + start);
	cmd->arg = ft_substr(cmd->arg, 0, start);
	if (!cmd->arg)
		return (0);
	if (ft_next_or_replace(&cmd, tmp, start, l) < 0)
		return (ft_free((void **)&tmp));
	cmd->flag = ft_make_quote_flag(flag, type, 1, cmd->first);
	if (tmp[start + l + 1])
	{
		arg = ft_substr(tmp, start + l + 1, ft_strlen(tmp + l + start));
		if (!arg)
			return (-1);
		if (ft_add_new_cmd(cmd, arg, ft_make_quote_flag(flag, 0, 1, 0)) < 0)
			return (ft_free((void **)&tmp));
	}
	*comd = cmd;
	free(tmp);
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
		if (l != -2)
			cmd = cmd->next;
		l = 0;
	}
	return (0);
}
