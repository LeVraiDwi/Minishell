/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pars2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:22:22 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 02:42:47 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_end_pars(t_parsing **first, t_parsing *new)
{
	t_parsing	*tmp;

	if (!*first)
		*first = new;
	else
	{
		tmp = *first;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_parsing	*ft_get_last_pars(t_parsing *pars)
{
	if (!pars)
		return (0);
	while (pars->next)
		pars = pars->next;
	return (pars);
}
