/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:26:48 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/27 17:13:15 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_lexer(t_cmd *cmd, char *str, char *tmp)
{
	if (cmd)
		ft_free_cmd(cmd);
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	return (0);
}

int	ft_skip_space(char *str, int start)
{
	int	i;

	i = 0;
	while (str[start + i] && ft_isspace(str[start + i]))
		i++;
	return (i);
}

int	new_cmd(t_cmd **new, char *str, int *l, int *i)
{
	char	*tmp;

	if (ft_isspace(str[*i]))
	{
		tmp = ft_substr(str, *l, *i - *l);
		if (!tmp)
			return (ft_free_lexer(*new, str, tmp));
		if (tmp && *tmp)
			if (ft_creat_cmd(new, tmp) < 0)
				return (ft_free_lexer(*new, str, tmp));
		free(tmp);
		tmp = 0;
		*i += ft_skip_space(str, *i);
		*l = *i;
	}
	else if (ft_isquote(str[*i]))
		*i = *i + new_cmd_quote(str, *i);
	else
		*i = *i + 1;
	return (1);
}

int	new_cmd_quote(char *str, int i)
{
	int		l;
	char	c;

	c = ft_is_quote(str[i]);
	if (c)
	{
		l = ft_quotelen(str, i, c);
		if (l > 0)
			return (l);
	}
	return (0);
}

t_cmd	*lexer(char *str)
{
	int		i;
	int		l;
	t_cmd	*new;

	i = 0;
	new = 0;
	i += ft_skip_space(str, i);
	l = i;
	while (str && str[i])
	{
		if (!new_cmd(&new, str, &l, &i))
			return (0);
	}
	if (str && str[l])
	{
		if (ft_creat_cmd(&new, str + l) < 0)
		{
			ft_free_lexer(new, str, 0);
			return (0);
		}
	}
	if (str)
		free(str);
	return (new);
}
