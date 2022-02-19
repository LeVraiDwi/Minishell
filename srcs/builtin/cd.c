/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:33 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:34:02 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_term *term, t_parsing *parsing)
{
	int	l;
	char	**cmd;

	cmd = parsing->argv;
	l = ft_cmd_length(cmd);
	if (l != 2)
	{
		errno = E2BIG;
		return (-1);
	}
	if (!cmd[1])
	{
		cmd[1] = get_env_var(term->env, "HOME");
		if (!cmd[1])
		{
			if (parsing->out > 1)
				close(parsing->out);
			parsing->out = 0;
			return (-1);
		}
	}
	if (chdir(cmd[1]) < 0)
	{
		perror("Error:");
		if (parsing->out > 1)
			close(parsing->out);
		parsing->out = 0;
		return (-1);
	}
	if (!ft_update_pwd(term))
		return (-1);
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}
