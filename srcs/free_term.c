/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:18:01 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:18:03 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_term(t_term **term)
{
	int	i;

	i = 0;
	while ((*term)->env[i])
	{
		free((*term)->env[i]);
		(*term)->env[i] = 0;
		i++;
	}
	if ((*term)->env)
		free((*term)->env);
	return (0);
}
