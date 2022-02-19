/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:20 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:33:44 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_term *term, t_parsing *parsing)
{
	char	**cmd;
	char	buf[1000];

	cmd = parsing->argv;
	(void)term;
	if (!strisstr(cmd[0], "pwd"))
	{
		if (parsing->out > 1)
			close(parsing->out);
		parsing->out = 0;
		return (-1);
	}
	getcwd(buf, 1000);
	write(parsing->out, buf, ft_strlen(buf));
	write(parsing->out, "\n", 1);
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}
