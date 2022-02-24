/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_char_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:16:37 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/23 19:23:01 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_len_spe(int flag)
{
	if (flag & HOME || flag & PIPE)
		return (1);
	if (flag & LAST_RET)
		return (2);
	if (flag & DOUBLE_REDIR_IN || flag & DOUBLE_REDIR_OUT)
		return (2);
	if (flag & SIMPLE_REDIR_IN || flag & SIMPLE_REDIR_OUT)
		return (1);
	return (0);
}

int	ft_is_interprete(t_cmd *cmd, int flag)
{
	if (flag && !(cmd->flag & SIMPLE_QUOTE) && !(cmd->flag & DOUBLE_QUOTE))
		return (1);
	return (0);
}
