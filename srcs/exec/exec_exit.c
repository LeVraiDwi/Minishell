/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:33:55 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 15:22:06 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_make_exit(t_term *term, t_parsing *exec, t_cmd **cmd, t_parsing *new)
{
	if (ft_is_exit(new))
	{
		ft_exit(term, exec, cmd, new);
		return (1);
	}
	return (0);
}
