/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:33:55 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 03:33:57 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_make_exit(t_term *term, t_parsing *exec, t_cmd **cmd, int in_pipe)
{
	if (!in_pipe && ft_is_exit(exec))
		ft_exit(term, exec, cmd);
	return (0);
}
