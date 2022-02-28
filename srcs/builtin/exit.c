/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:19:47 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 20:51:02 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_term *term, t_parsing *parsing, t_cmd **tab)
{
	char	**cmd;
	int		code;

	cmd = parsing->argv;
	if (!cmd[1])
		exit(0);
	if (!isnumber(cmd[1]))
	{
		write(2, MINISHELL, ft_strlen(MINISHELL));
		write(2, ": exit: ", 9);
		write(2, cmd[1], ft_strlen(cmd[1]));
		write(2, "numeric argument required\n", 27);
		ft_free_cmd_tab(tab);
		ft_free_pars(parsing);
		ft_free_term(term);
		exit (-1);
	}
	if (ft_cmd_length(cmd) > 2)
	{
		write(2, MINISHELL, ft_strlen(MINISHELL));
		write(2, ": exit: too many arguments", 9);
		return (-1);
	}
	ft_free_cmd_tab(tab);
	ft_free_pars(parsing);
	ft_free_term(term);
	code = ft_atoi(cmd[1]);
	exit(code);
}
