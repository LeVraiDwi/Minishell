/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:33:47 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 17:19:06 by tcosse           ###   ########.fr       */
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
	cmd  = 0;
	tab = 0;
	return (-1);
}

int	ft_perror(void)
{
	err = 1;
	perror(MINISHELL);
	return (-1);
}

int	ft_set_ret_err(void)
{
	err = 1;
	return (-1);
}

int	set_status_err(int	status, int success)
{
	if (status == 2)
		err = 130;
	else if (status)
	{
		perror(MINISHELL);
		err = 1;
	}
	else
		err = success;
	return (-1);
}
