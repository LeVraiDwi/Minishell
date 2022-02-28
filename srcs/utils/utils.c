/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:27:05 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 15:06:57 by asaboure         ###   ########.fr       */
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

int	ft_close(int fd1, int fd2)
{
	if (fd1 > 1)
		close(fd1);
	if (fd2 > 1)
		close(fd2);
	return (-1);
}

int	isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}