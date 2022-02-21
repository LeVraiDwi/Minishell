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

	i = ft_is_spe_var(cmd, l);
	if (i)
		return (i);
	else if (ft_is_home(cmd, l, flag))
		return (1);
	else if (cmd[l] == '|')
		return (1);
	else
	{
		i = ft_is_redir(cmd, l);
		if (i)
			return (i);
	}
	return (0);
}

int	ft_is_spe_var(char *cmd, int l)
{
	int	i;

	i = 0;
	if (cmd[l] == '$' && (cmd[l + 1]
			&& (ft_isalnum(cmd[l + 1]) || cmd[l + 1] == '_')))
	{
		i++;
		while (ft_isalnum(cmd[l + i]) || cmd[l + i] == '_')
			i++;
	}
	else if (cmd[l] == '$' && cmd[l + 1] == '?')
		return (2);
	return (i);
}

int	ft_is_redir(char *cmd, int l)
{
	if (cmd[l] == '<')
	{
		if (cmd[l + 1] == '<')
			return (2);
		else
			return(1);
	}
	else if (cmd[l] == '>')
	{
		if (cmd[l + 1] == '>')
			return (2);
		else
			return(1);
	}
	return (0);
}

int	ft_is_home(char *cmd, int l, int flag)
{
	if ((flag & DOUBLE) || (flag & SIMPLE))
		return (0);
	if (!cmd || !cmd[l])
		return (0);
	if (cmd[l] == '~' && (cmd[l + 1] == 0 || cmd[l + 1] == ' '
			|| ft_is_special_char(cmd, l + 1, flag) || cmd[l + 1] == '/')
			&& (l == 0 || (l > 0 && cmd[l - 1] == ' ')))
		return (1);
	return (0);
}
