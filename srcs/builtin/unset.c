/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:27 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 22:23:04 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_valid_name(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

void	remove_env_lst(t_term *term, char **cmd, int *ret)
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
			write(2, "unset: %s: invalid parameter name\n", ft_strlen(cmd[0]));
			write(2, ": ", 2);
			write(2, cmd[l], ft_strlen(cmd[l]));
			write(2, ": invalid parameter name\n", 26);
			*ret = 1;
		}
		l++;
	}
}

int	ft_unset(t_term *term, t_parsing *parsing)
{
	int	ret;
	char	**cmd;

	ret = 0;
	cmd = parsing->argv;
	if (!parsing->next)
	{
		remove_env_lst(term, cmd, &ret);
	}
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (ret);
}
