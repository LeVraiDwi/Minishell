/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:28:34 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/25 14:22:00 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	expanser(t_term *term, t_cmd **tab)
{
	int	i;
	t_cmd	*tmp;

	i = 0;
	while (tab[i])
	{
		tmp = tab[i];
		if (ft_replace_cmd(term, tmp) < 0)
			return (-1);
		i++;
	}
	return (0);
}
