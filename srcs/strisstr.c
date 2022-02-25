/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:18:24 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/25 18:39:11 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strisstr(char *str, char *s)
{
	int	i;

	i = 0;
	if (!str || !s)
		return (0);
	while (str[i] && s[i] && str[i] == s[i])
		i++;
	if (str[i] || s[i])
		return (0);
	return (1);
}
