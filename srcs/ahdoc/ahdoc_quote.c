/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahdoc_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:51:20 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 17:51:21 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_limiter(t_cmd *next, char **limiter, int *flag)
{
	char	*tmp;

	tmp = *limiter;
	*limiter = ft_strjoin(*limiter, next->arg);
	free(tmp);
	if (!*limiter)
		return (-1);
	ft_add_flag(next, IGNORE);
	if ((next->flag & SIMPLE_QUOTE) || (next->flag & DOUBLE_QUOTE))
		*flag = 1;
	return (0);
}
