/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:29:32 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 01:34:20 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *cmd)
{
	if (strisstr("cd", cmd))
		return (CD);
	if (strisstr("pwd", cmd))
		return (PWD);
	if (strisstr("export", cmd))
		return (EXPORT);
	if (strisstr("unset", cmd))
		return (UNSET);
	if (strisstr("env", cmd))
		return (ENV);
	if (strisstr("echo", cmd))
		return (ECHO);
	if (strisstr("exit", cmd))
		return (EXIT);
	return (-1);
}

int	ft_cmd_length(char **cmd)
{
	int	l;

	l = 0;
	while (cmd[l])
		l++;
	return (l);
}

int	is_flag(char *arg)
{
	if (!arg || ft_strlen(arg) != 2)
		return (0);
	if (arg[0] == '-' && arg[1] == 'n')
		return (FLAG_N);
	return (0);
}
