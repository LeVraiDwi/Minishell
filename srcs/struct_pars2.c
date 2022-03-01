/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pars2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:22:22 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 02:22:48 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_end_pars(t_parsing **first, t_parsing *new)
{
	t_parsing	*tmp;

	printf("seg\n");
	if (first)
	{
		if (!*first)
			*first = new;
		else
		{
			tmp = *first;
			printf("seg %p\n", tmp);
			while (tmp && tmp->next)
				tmp = tmp->next;
			printf("seg %p\n", tmp);
			printf("seg\n");
			tmp->next = new;
			printf("seg\n");
		}
		printf("seg end\n");
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
