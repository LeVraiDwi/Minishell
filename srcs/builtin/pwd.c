/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:20 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 21:38:17 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_term *term, t_parsing *parsing)
{
	char	**cmd;

	cmd = parsing->argv;
	(void)term;
	if (!strisstr(cmd[0], "pwd"))
	{
		if (parsing->out > 1)
			close(parsing->out);
		parsing->out = 0;
		return (-1);
	}
	write(parsing->out, term->cwd, ft_strlen(term->cwd));
	write(parsing->out, "\n", 1);
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}
