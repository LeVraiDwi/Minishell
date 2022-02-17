/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:04:49 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 17:05:37 by tcosse           ###   ########.fr       */
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

int	ft_openfile(char *path, int flags, int right)
{
	int	fd;

	if (!path)
		return (0);
	if (!access(path, F_OK))
	{
		if (ft_isfile(path) < 0)
			return (-1);
		if (ft_checkright(path, right))
			return (-1);
		fd = open(path, flags | right);
	}
	else
		fd = open(path, O_CREAT | right | right,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	ft_setfilename(t_parsing *parsing)
{
	t_parsing	*tmp;

	tmp = parsing->next;
	if (parsing->str_out && !tmp->str_in)
	{
		tmp->str_in = ft_strdup(parsing->str_out);
		if (!tmp->str_in)
			return (-1);
	}
	return (0);
}
