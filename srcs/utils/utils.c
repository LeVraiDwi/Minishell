/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:27:05 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/21 17:27:06 by tcosse           ###   ########.fr       */
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
			return (l);
		l++;
	}
	return (-1);
}
