/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:33:47 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/27 18:32:48 by tcosse           ###   ########.fr       */
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
	perror(MINISHELL);
	return (-1);
}
