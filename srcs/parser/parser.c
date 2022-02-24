/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:51:07 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/24 19:15:26 by tcosse           ###   ########.fr       */
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
/*	if (ft_check_redir(cmd))
		printf("erreur\n");*/
/*	if (ahdoc(term, cmd) < 0)
		return (-1);*/
	return (0);
}
