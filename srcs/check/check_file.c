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
