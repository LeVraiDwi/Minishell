/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:27 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:32:46 by tcosse           ###   ########.fr       */
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

int	ft_unset(t_term *term, t_parsing *parsing)
{
	int	l;
	int	flag;
	int	ret;
	char	**cmd;

	l = 0;
	flag = 0;
	ret = 0;
	cmd = parsing->argv;
	if (!parsing->next)
	{
		while (cmd[l])
		{
			if (ft_is_valid_name(cmd[l]))
			{
				ret = 0;
				remove_env(term, cmd[l]);
			}
			else if (!flag)
			{
				printf("unset: %s: invalide parameter name\n", cmd[l]);
				flag = 1;
				ret = 1;
			}
			else
				ret = 1;
			l++;
		}
	}
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (ret);
}
