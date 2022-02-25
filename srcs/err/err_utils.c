/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:33:47 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/25 18:34:18 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err(t_term *term)
{
	int	i;

	if (!term->is_err || !term->err)
		return ;
	i = 0;
	while (term->err[i])
	{
		write(2, "minishell: ", 11);
		write(2, term->err[i], ft_strlen(term->err[i]));
		write(2, "\n", 1);
		i++;
	}
	ft_free_term_err(term);
	return ;
}
