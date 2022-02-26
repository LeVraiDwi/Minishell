/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:34:26 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/26 16:16:28 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_err(t_cmd *cmd, t_cmd *first, int err_num)
{
	(void)first;
	if (err_num == SYNTAX_ERR)
		return (ft_set_syntax_err(cmd));
	return (0);
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
		write (2, SYNTAX_STR, ft_strlen(SYNTAX_STR));
		write (2, str, 1);
		write (2, "\'\n", 2);
	}
	return (-1);
}

char	*ft_creat_err_msg(char *arg, int err)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(arg, ": ");
	if (!tmp)
		return (0);
	new = ft_strjoin(tmp, strerror(err));
	if (tmp)
		free(tmp);
	if (!new)
		return (0);
	return (new);
}
/*
int	ft_add_err(t_term *term, char *str)
{
	int		l;
	char	**new;

	l = 0;
	while (term->err && term->err[l])
		l++;
	new = (char **)malloc(sizeof(char *) * (l + 2));
	if (!new)
		return (-1);
	new[l + 1] = 0;
	l = 0;
	while (term->err && term->err[l])
	{
		new[l] = term->err[l];
		l++;
	}
	new[l] = str;
	if (term->err)
		free(term->err);
	term->err = new;
	return (0);
}*/

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
