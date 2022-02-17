/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:12 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 14:18:42 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_var(char *var)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (!var)
		return (0);
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	if (var[i] == '=')
		return (1);
	return (0);
}

int	ft_export(t_term *term, char **cmd)
{
	int	l;
	int	flag;
	int	ret;

	l = 1;
	flag = 0;
	ret = 0;
	while (cmd[l])
	{
		if (ft_is_var(cmd[l]))
		{
			ret = 0;
			if (add_env(term, cmd[l]) < 0)
				return (-1);
		}
		else if (!flag)
		{
			ret = 1;
			printf("export: %s: invalide parameter name\n", cmd[l]);
			flag = 1;
		}
		else
			ret = 1;
		l++;
	}
	return (0);
}
