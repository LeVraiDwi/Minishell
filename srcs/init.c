/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:18:13 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 18:12:02 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_built(t_term *term)
{
	term->built[0] = &ft_cd;
	term->built[1] = &ft_export;
	term->built[2] = &ft_unset;
	term->built[3] = &ft_pwd;
	term->built[4] = &ft_env;
	term->built[5] = &ft_echo;
	term->exit = &ft_exit;
}

int	init_term(t_term *term, char **env)
{
	if (!ft_init_env(term, env))
		return (-1);
	init_built(term);
	getcwd(term->cwd, 1000);
	ft_set_pwd(term);
	term->act_cmd = 0;
	rl_clear_history();
	return (0);
}
