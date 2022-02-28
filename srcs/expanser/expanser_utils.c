/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:06:04 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 18:23:05 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_replace_cmd(t_term *term, t_cmd *cmd)
{
	if (!cmd)
		return (0);
	while (cmd)
	{
		if (cmd->arg && ((cmd->flag & VAR)
				|| (cmd->flag & HOME) || (cmd->flag & LAST_RET)))
			if (ft_insert_var(cmd, term->env) < 0)
				return (-1);
		cmd = cmd->next;
	}
	return (0);
}

int	get_ret(t_cmd *cmd)
{
	if (cmd->arg)
		free(cmd->arg);
	cmd->arg = ft_itoa(g_err);
	if (!cmd->arg)
		return (-1);
	return (0);
}

int	ft_insert_var(t_cmd *cmd, char **env)
{
	char	*var;

	var = 0;
	if (cmd->flag & LAST_RET)
		return (get_ret(cmd));
	else if (cmd->flag & VAR)
		var = ft_substr(cmd->arg, 1, ft_strlen(cmd->arg + 1));
	else if (cmd->flag & HOME)
		var = ft_strdup(HOME_STR);
	if (!var)
		return (-1);
	if (cmd->arg)
		free(cmd->arg);
	cmd->arg = get_env_var(env, var);
	if (var)
		free(var);
	if (!cmd->arg)
		return (-1);
	return (0);
}
