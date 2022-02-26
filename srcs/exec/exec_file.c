/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:04:49 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/26 15:59:13 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isfile(char *path)
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

int	ft_checkright(char *path, int right)
{
	if (right & O_RDONLY)
		if (access(path, R_OK))
			return (-1);
	if (right & O_WRONLY)
		if (access(path, W_OK))
			return (-1);
	if (right & O_RDWR)
		if (access(path, R_OK | W_OK))
			return (-1);
	return (0);
}

int	ft_openfile(char *path, int right, int mode, int flag)
{
	int	fd;

	if (!path)
		return (-1);
	if (!access(path, F_OK))
	{
		if (ft_isfile(path) < 0)
			return (-1);
		if (ft_checkright(path, right))
			return (-1);
		fd = open(path, right | mode);
	}
	else if (!(flag & SIMPLE_REDIR_IN))
		fd = open(path, O_CREAT | right | mode,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	else
		return (-1);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	ft_stdopen(t_cmd *cmd, char *path)
{
	int	fd;

	if (!path)
		return (ft_error_std(cmd, errno));
	fd = 0;
	if (cmd->flag & SIMPLE_REDIR_IN)
		fd = ft_openfile(path, O_APPEND, O_RDONLY, cmd->flag);
	if (cmd->flag & SIMPLE_REDIR_OUT)
		fd = ft_openfile(path, O_APPEND, O_RDWR, cmd->flag);
	if (cmd->flag & DOUBLE_REDIR_OUT)
		fd = ft_openfile(path, O_TRUNC, O_RDWR, cmd->flag);
	if (fd < 0)
		return (ft_error_std(cmd, errno));
	cmd->pipefd[0] = fd;
	return (0);
}
