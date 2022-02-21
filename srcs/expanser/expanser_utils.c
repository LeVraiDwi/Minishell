/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:06:04 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 17:17:27 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_var_len(char *var)
{
	int	i;

	i = 0;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return (i);
}

int	ft_is_special_char(char *cmd, int l, int flag)
{
	int	i;

	i = 0;
	if (cmd[l] == '$' && (cmd[l + 1]
			&& (ft_isalnum(cmd[l + 1]) || cmd[l + 1] == '_')))
	{
		i++;
		while (ft_isalnum(cmd[l + i]) || cmd[l + i] == '_')
			i++;
		return (i);
	}
	else if (ft_is_home(cmd, l, flag))
		return (1);
	return (0);
}

int	insert_var(char **env, char **cmd, int flag)
{
	int		l;
	int		i;

	i = 0;
	if (!cmd || !*cmd)
		return (0);
	l = ft_is_special_char(*cmd, i, flag);
	if (l)
		if (ft_insert_var(cmd, l, i, env) < 0)
			return (-1);
	return (0);
}

char	*ft_insertvar(char *s, char *str, int var_start, int var_l)
{
	int		l;
	char	*new;

	if (!s)
		return (0);
	l = 0;
	l = ft_strlen(s) + ft_strlen(str) - var_l;
	new = (char *)malloc(sizeof(char) * (l + 1));
	new[l] = 0;
	l = 0;
	while (*s)
	{
		if (l == var_start)
		{
			while (str && *str)
				new[l++] = *str++;
			s += var_l;
		}
		new[l++] = *s++;
	}
	return (new);
}

int	ft_replace_cmd(t_term *term, t_cmd *cmd)
{
	t_cmd	*tmp;

	if (!cmd)
		return (0);
	tmp = cmd;
	while (tmp)
	{
		if (tmp->arg && !(tmp->flag & SIMPLE))
			if (insert_var(term->env, &tmp->arg, tmp->flag) < 0)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
}
