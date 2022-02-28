/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:19:47 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 15:40:40 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_term *term, t_parsing *parsing)
{
	char	**cmd;
	int		code;

	cmd = parsing->argv;
	if (ft_cmd_length(cmd) > 2)
	{
		errno = E2BIG;
		return (-1);
	}
	ft_free_term(term);
	if (!cmd[1])
		exit(0);
	if (!isnumber(cmd[1]))
	{
		errno = EINVAL;
		exit (-1);
	}
	code = ft_atoi(cmd[1]);
	exit(code);
}