/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:04:49 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/24 16:21:56 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdir(char *path)
{
	DIR	*dp;

	dp = opendir(path);
	if (dp)
	{
		errno = EISDIR;
		closedir(dp);
		return (-1);
	}
	closedir(dp);
	return (0);
}

int	ft_check_file(t_cmd *cmd)
{
	t_cmd	*next;

	next = (t_cmd *)cmd->next;
	if (access(next->arg, F_OK) == 0)
	{
		if (ft_isdir(next->arg) < 0)
			return (-1);
		if (cmd->flag & SIMPLE_REDIR_IN)
			if (access(cmd->arg, R_OK) < 0)
				return (-1);
		if ((cmd->flag & SIMPLE_REDIR_OUT) || (cmd->flag & DOUBLE_REDIR_OUT))
			if (access(cmd->arg, R_OK | W_OK) < 0)
				return (-1);
	}
	else
		if (cmd->flag & SIMPLE_REDIR_IN)
			return (-1);
	return (0);
}

int	check_file(t_cmd *cmd)
{
	while (cmd)
	{
		if ((cmd->flag & IS_REDIR)
			&& !(cmd->flag & DOUBLE_REDIR_IN) && !(cmd->flag & IGNORE))
		{
			if (!ft_check_file(cmd))
				return (-1);
		}
		cmd = cmd->next;
	}
	return (0);
}
