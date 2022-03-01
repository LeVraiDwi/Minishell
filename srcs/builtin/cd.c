/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:33 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 21:37:12 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_to_path(char *path, t_parsing *parsing, t_term *term, int flag)
{
	if (chdir(path) < 0)
	{
		if (parsing->out > 1)
			close(parsing->out);
		parsing->out = 0;
		if (flag)
			free(path);
		return (ft_perror());
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

int	ft_cd(t_term *term, t_parsing *parsing)
{
	char	*path;
	int		flag;

	flag = 0;
	path = parsing->argv[1];
	if (ft_cmd_length(parsing->argv) > 2)
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
	return (go_to_path(path, parsing, term, flag));
}
