/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:19:47 by asaboure          #+#    #+#             */
/*   Updated: 2022/03/01 17:07:01 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_minishell(t_cmd **tab, t_parsing *parsing, t_term *term)
{
	ft_free_cmd_tab(tab);
	ft_free_pars(parsing);
	ft_free_term(term);
	rl_clear_history();
}

int	ft_exit(t_term *term, t_parsing *parsing, t_cmd **tab, t_parsing *pars)
{
	char	**cmd;
	int		code;

	cmd = pars->argv;
	if (!cmd[1])
	{
		destroy_minishell(tab, parsing, term);
		exit(0);
	}
	if (!isnumber(cmd[1]))
	{
		write(2, MINISHELL, ft_strlen(MINISHELL));
		write(2, ": exit: ", 9);
		write(2, cmd[1], ft_strlen(cmd[1]));
		write(2, ": numeric argument required\n", 29);
		destroy_minishell(tab, parsing, term);
		exit(-1);
	}
	if (ft_cmd_length(cmd) > 2)
	{
		write(2, MINISHELL, ft_strlen(MINISHELL));
		write(2, ": exit: too many arguments", 9);
		return (-1);
	}
	code = ft_atoi(cmd[1]);
	destroy_minishell(tab, parsing, term);
	exit(code);
}
