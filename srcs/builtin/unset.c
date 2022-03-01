/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:27 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 23:56:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_valid_name(char *cmd)
{
	int	i;

	i = 0;
	if (!*cmd)
		return (0);
	if (ft_isdigit(cmd[i]))
		return (0);
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

void	remove_env_lst(t_term *term, char **cmd)
{
	int	l;

	l = 0;
	while (cmd[l])
	{
		if (ft_is_valid_name(cmd[l]))
		{
			remove_env(term, cmd[l]);
		}
		else
		{
			write(2, "unset: `", 9);
			write(2, cmd[l], ft_strlen(cmd[l]));
			write(2, "': invalid parameter name\n", 27);
			g_err = 1;
		}
		l++;
	}
}

int	ft_unset(t_term *term, t_parsing *parsing)
{
	char	**cmd;

	cmd = parsing->argv;
	if (!parsing->next)
	{
		remove_env_lst(term, cmd);
	}
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}
