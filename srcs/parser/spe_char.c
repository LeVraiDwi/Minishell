/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:06:04 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/21 18:35:13 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_special_char(char *cmd, int l, int flag)
{
	int	i;

	i = ft_is_spe_var(cmd, l, flag);
	if (i)
		return (i);
	else if (ft_is_home(cmd, l, flag))
		return (HOME);
	else if (cmd[l] == '|')
		return (PIPE);
	else
	{
		i = ft_is_redir(cmd, l, flag);
		if (i)
			return (i);
	}
	return (0);
}

int	ft_is_spe_var(char *cmd, int l, int flag)
{
	int	i;

	i = 0;
	if (flag & SIMPLE_QUOTE)
		return (0);
	if (cmd[l] == '$' && (cmd[l + 1]
			&& (ft_isalnum(cmd[l + 1]) || cmd[l + 1] == '_')))
		return (VAR);
	else if (cmd[l] == '$' && cmd[l + 1] == '?')
		return (LAST_RET);
	return (0);
}

int	ft_is_redir(char *cmd, int l, int flag)
{
	if ((flag & SIMPLE_QUOTE) || (flag & DOUBLE_QUOTE))
		return (0);
	if (cmd[l] == '<')
	{
		if (cmd[l + 1] == '<')
			return (DOUBLE_REDIR_IN);
		else
			return(SIMPLE_REDIR_IN);
	}
	else if (cmd[l] == '>')
	{
		if (cmd[l + 1] == '>')
			return (DOUBLE_REDIR_OUT);
		else
			return(SIMPLE_REDIR_OUT);
	}
	return (0);
}

int	ft_is_home(char *cmd, int l, int flag)
{
	if ((flag & DOUBLE_QUOTE) || (flag & SIMPLE_QUOTE))
		return (0);
	if (!cmd || !cmd[l])
		return (0);
	if (cmd[l] == '~' && (cmd[l + 1] == 0 || cmd[l + 1] == ' '
			|| ft_is_special_char(cmd, l + 1, flag) || cmd[l + 1] == '/')
			&& (l == 0 || (l > 0 && cmd[l - 1] == ' ')))
		return (1);
	return (0);
}
