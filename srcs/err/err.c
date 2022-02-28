/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:34:26 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 20:28:03 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_err(t_cmd *cmd, int err_num)
{
	if (err_num == SYNTAX_ERR)
	{
		g_err = 2;
		ft_set_syntax_err(cmd);
	}
	else if (err_num == PERROR_ERR)
	{
		g_err = 1;
		perror(MINISHELL);
	}
	return (-1);
}

int	ft_set_syntax_err(t_cmd *cmd)
{
	t_cmd	*next;
	char	str[1];

	next = (t_cmd *)cmd->next;
	if (next)
		str[0] = next->arg[0];
	if (!cmd->next)
		write(2, SYNTAX_ERR_NEW_LINE, ft_strlen(SYNTAX_ERR_NEW_LINE));
	else
	{
		write(2, MINISHELL, ft_strlen(MINISHELL));
		write(2, SYNTAX_STR, ft_strlen(SYNTAX_STR));
		write(2, str, 1);
		write(2, "\'\n", 2);
	}
	return (-1);
}

int	ft_error_cmd(char *str)
{
	if (str && *str)
		write(2, str, ft_strlen(str));
	else
		write(2, "\'\'", 2);
	write(2, ": ", 2);
	write(2, CMD_NOT_FOUND, ft_strlen(CMD_NOT_FOUND));
	write(2, "\n", 1);
	g_err = 127;
	return (-1);
}

int	ft_error_std(t_cmd *cmd, int err)
{
	t_cmd	*next;
	char	*str;

	(void)err;
	str = strerror(err);
	next = (t_cmd *)cmd->next;
	write(2, "minishell: ", ft_strlen("minishell: "));
	if (next && next->arg)
		write(2, next->arg, ft_strlen(next->arg));
	write(2, ": ", 2);
	write(2, strerror(err), ft_strlen(strerror(err)));
	write(2, "\n", 1);
	return (-1);
}
