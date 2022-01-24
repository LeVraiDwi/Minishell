/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:29:32 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:32:17 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *cmd)
{
	if (strisstr("cd", cmd))
		return (CD);
	if (strisstr("pwd", cmd))
		return (PWD);
	if (strisstr("export", cmd))
		return (EXPORT);
	if (strisstr("unset", cmd))
		return (UNSET);
	if (strisstr("env", cmd))
		return (ENV);
	if (strisstr("echo", cmd))
		return (ECHO);
	if (strisstr("EXIT", cmd))
		return (-1);
	return (-1);
}
