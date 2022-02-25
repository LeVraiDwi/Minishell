/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:51:07 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/25 16:55:33 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	if (split_quote(cmd) < 0)
		return (-1);
	if (split_spe_char(cmd) < 0)
		return (-1);
	ft_set_cmd(cmd);
/*	if (ft_check_redir(cmd))
		printf("erreur\n");*/
/*	if (ahdoc(term, cmd) < 0)
		return (-1);*/
	return (0);
}
