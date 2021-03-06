/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:05 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:21:06 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_term *term, t_parsing *parsing)
{
	char	**cmd;

	cmd = parsing->argv;
	if (cmd[1])
	{
		strerror(E2BIG);
		if (parsing->out > 1)
			close(parsing->out);
		parsing->out = 0;
		return (-1);
	}
	print_env(*term, parsing->out);
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}
