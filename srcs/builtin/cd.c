/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:33 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 00:52:50 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_term *term, t_parsing *parsing)
{
	int	l;
	char	*path;
	int	flag;

	flag = 0;
	path = parsing->argv[1];
	l = ft_cmd_length(parsing->argv);
	if (l > 2)
	{
		errno = E2BIG;
		return (ft_perror());
	}
	if (!path)
	{
		path = get_env_var(term->env, "HOME");
		if (!path)
		{
			if (parsing->out > 1)
				close(parsing->out);
			parsing->out = 0;
			return (-1);
		}
		flag = 1;
	}
	if (chdir(path) < 0)
	{
		perror("Error:");
		if (parsing->out > 1)
			close(parsing->out);
		parsing->out = 0;
		if (flag)
			free(path);
		return (-1);
	}
	if (flag)
		free(path);
	if (!ft_update_pwd(term))
		return (-1);
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}
