/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:40 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 14:01:45 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_flag(char *arg)
{
	if (!arg || ft_strlen(arg) != 2)
		return (0);
	if (arg[0] == '-' && arg[1] == 'n')
		return (FLAG_N);
	return (0);
}

void	ft_echo_new_line(int flag)
{
	if (flag != FLAG_N)
		write(1, "\n", 1);
}

int	ft_cmd_length(char **cmd)
{
	int	l;

	l = 0;
	while (cmd[l])
		l++;
	return (l);
}

int	return_new_line(void)
{
	write(1, "\n", 1);
	return (0);
}

int	ft_echo(t_term *term, t_parsing *parsing)
{
	int	flag;
	int	i;
	int	l;
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
	if (flag)
		i = 2;
	else
		i = 1;
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
