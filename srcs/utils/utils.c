/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:27:05 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 00:13:52 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_isquote(char c)
{
	if (c == '\'' || c == '\"')
		return (c);
	return (0);
}

int	ft_quotelen(char *str, int start, char c)
{
	int	l;

	l = 0;
	if (ft_isquote(str[start + l]))
		l++;
	while (str[start + l])
	{
		if (ft_isquote(str[start + l]) == c)
			return (l + 1);
		l++;
	}
	return (1);
}

char	*ft_insertvar(char *s, char *str, int var_start, int var_l)
{
	int		l;
	char	*new;

	if (!s)
		return (0);
	l = 0;
	l = ft_strlen(s) + ft_strlen(str) - var_l;
	new = (char *)malloc(sizeof(char) * (l + 1));
	if (!new)
		return (0);
	new[l] = 0;
	l = 0;
	while (*s)
	{
		if (l == var_start)
		{
			while (str && *str)
				new[l++] = *str++;
			s += var_l;
		}
		new[l++] = *s++;
	}
	return (new);
}
