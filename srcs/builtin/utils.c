/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:29:32 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 17:36:17 by asaboure         ###   ########.fr       */
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

int	is_flag(char **arg)
{
	int	i;
	int	j;

	j = 1;
	if (!arg[j][0])
		return (j);
	while (arg[j][0] == '-')
	{
		i = 1;
		while (arg[j][i])
		{
			if (arg[j][i] != 'n')
				return (j);
			i++;
		}
		j++;
	}
	return (j);
}
