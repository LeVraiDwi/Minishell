/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:03:50 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/23 16:59:47 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_join(char **std, t_cmd *cmd)
{
	char	*tmp;

	tmp = ft_strjoin(*std, cmd->arg);
	if (!tmp)
		return (-1);
	if (*std)
		free(*std);
	*std = tmp;
	return (0);
}

int	ft_insert_var(char **cmd, int l, int i, char **env)
{
	char	*tmp;
	char	*var;

	if ((*cmd)[i] == '$')
	{
		tmp = ft_substr(*cmd, i + 1, l - 1);
		if (!tmp)
			return (-1);
	}
	else
		tmp = ft_strdup(HOME);
	var = get_env_var(env, tmp);
	if (tmp)
		free(tmp);
	tmp = ft_insertvar(*cmd, var, i, l);
	if (var)
		free(var);
	if (!tmp)
		return (-1);
	free(*cmd);
	*cmd = tmp;
	return (0);
}

int	ft_add_new_cmd(t_cmd *cmd, char *tmp, int start, int len_q)
{
	t_cmd	*new;

	new = ft_init_cmd();
	if (!new)
		return (ft_free((void **)&tmp));
	ft_add_next_cmd((t_cmd *)cmd->next, new);
	new->flag = cmd->flag;
	if (!(new->flag & JOIN))
		new->flag += JOIN;
	new->arg = ft_substr(tmp, start + len_q
			+ 1, ft_strlen(tmp + start + len_q + 1));
	free(tmp);
	if (!new->arg)
		return (-1);
	return (1);
}

int	ft_do_quote(t_cmd **cmd, int i, int *l)
{
	if (ft_is_quote((*cmd)->arg[i]))
	{
		if (((*cmd)->arg[i] == '\"' && !((*cmd)->flag & SIMPLE))
			|| ((*cmd)->arg[i] == '\'' && !((*cmd)->flag & DOUBLE)))
		{
			*l = ft_quote_len((*cmd)->arg + i);
			if (*l >= 0)
				if (ft_split_quote(*cmd, *l, ft_is_quote((*cmd)->arg[i]), i))
					return (ft_free_cmd((*cmd)));
			*l = -2;
		}
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
