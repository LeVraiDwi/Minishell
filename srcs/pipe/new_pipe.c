/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:51:11 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 17:51:38 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_valid_cmd(char *str)
{
	if (!str || !*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (str)
		return (1);
	return (0);
}

t_cmd	*new_pipe(t_cmd *cmd)
{
	t_cmd	*next;

	next = (t_cmd *)cmd->next;
	cmd->next = 0;
	return (next);
}
