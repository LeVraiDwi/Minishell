/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:17:41 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/23 15:44:22 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_in_out(t_parsing *parsing)
{
	int			pipefd[2];
	t_parsing	*next;

/*	if (pipe(pipefd) < 0)
		return (-1);
	next = parsing->next;
	if (!next->str_in)
	{
		parsing->pipe_out = pipefd;
		((parsing *)(parsing->next))->pipe_in = pipefd;
	}*/
	return (0);
}
