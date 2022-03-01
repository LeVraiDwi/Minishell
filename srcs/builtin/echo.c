/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:40 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 01:47:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_new_line(int flag)
{
	if (flag != FLAG_N)
		write(1, "\n", 1);
}

int	return_new_line(void)
{
	write(1, "\n", 1);
	return (0);
}

static int	flag_ternary(int flag)
{
	int	i;

	i = 1;
	if (flag)
		i = 2;
	return (i);
}

int	ft_echo_end(int l, t_parsing *parsing, char **cmd, int flag)
{
	int	i;

	i = flag_ternary(flag);
	while (i < l)
	{
		write(parsing->out, cmd[i], ft_strlen(cmd[i]));
		i++;
		if (i < l)
			write(parsing->out, " ", 1);
	}
	ft_echo_new_line(flag);
	if (parsing->out > 1)
		close(parsing->out);
	parsing->out = 0;
	return (0);
}

int	ft_echo(t_term *term, t_parsing *parsing)
{
	int		flag;
	int		l;
	char	**cmd;

	cmd = parsing->argv;
	(void)term;
	l = ft_cmd_length(cmd);
	flag = 0;
	if (l == 1)
	{
		if (parsing->out > 1)
			close(parsing->out);
		return (return_new_line());
	}
	else if (l > 1)
		flag = is_flag(cmd[1]);
	return (ft_echo_end(l, parsing, cmd, flag));
}
