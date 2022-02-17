/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:17:41 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 17:18:07 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_in_out(t_parsing *parsing)
{
	int			pipefd[2];
	t_parsing	*next;

	if (pipe(pipefd) < 0)
		return (-1);
	next = parsing->next;
	if (parsing->out == STDOUT && !next->str_in)
	{
		parsing->out = pipefd[1];
		next->in = pipefd[0];
	}
	return (0);
}
