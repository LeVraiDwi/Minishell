/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:33:47 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 23:27:50 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_err_cmd(t_cmd *cmd, t_cmd **tab, int perr)
{
	if (perr)
		perror(MINISHELL);
	if (cmd)
		ft_free_cmd(cmd);
	if (tab)
		ft_free_cmd_tab(tab);
	cmd = 0;
	tab = 0;
	return (-1);
}

int	ft_perror(void)
{
	g_err = 1;
	perror(MINISHELL);
	return (-1);
}

int	ft_set_ret_err(void)
{
	g_err = 1;
	return (-1);
}

int	set_status_err(int status, int success)
{
	if (status == 2)
	{
		write(1, "\n", 1);
		g_err = 130;
	}
	else if (status == 131)
	{
		write(1, "Quit (core dumped)\n", 20);
		g_err = 131;
	}
	else if (status)
		g_err = 1;
	else
	{
		g_err = success;
		return (0);
	}
	return (-1);
}

int	ft_ret_err(void)
{
	exit(EXIT_FAILURE);
	return (-1);
}
