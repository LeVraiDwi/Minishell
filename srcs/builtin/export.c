/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:12 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 23:56:28 by asaboure         ###   ########.fr       */
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
	if (ft_isdigit(var[i]))
		return (0);
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return (i);
}

int	ft_export_lst(t_term *term, char **cmd)
{
	int	l;
	int	i;

	l = 1;
	while (cmd[l])
	{
		i = ft_is_var(cmd[l]);
		if (cmd[l][i] == '=' && i != 0)
		{
			if (add_env(term, cmd[l]) < 0)
				return (-1);
		}
		else if (!cmd[l][0] || (cmd[l][i] || (i == 0 && cmd[l][i] == '=')))
		{
			write(2, "export: `", 10);
			write(2, cmd[l], ft_strlen(cmd[l]));
			write(2, "': invalid parameter name\n", 27);
			g_err = 1;
		}
		l++;
	}
	return (0);
}

int	ft_export(t_term *term, t_parsing *parsing)
{
	char	**cmd;

	cmd = parsing->argv;
	if (!cmd[1])
	{
		ft_env(term, parsing);
		return (0);
	}
	if (!parsing->next)
		if (ft_export_lst(term, cmd) < 0)
			return (-1);
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}
