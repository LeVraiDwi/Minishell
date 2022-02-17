/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:30:26 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 17:03:32 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_join_arg(t_cmd *tmp, char **new, int *l)
{
	char	*c_tmp;

	if (!(tmp->flag & JOIN))
	{
		if (new[*l])
			*l += 1;
		new[*l] = ft_strdup(tmp->arg);
		if (!new[*l])
			return (-1);
	}
	else
	{
		c_tmp = new[*l];
		new[*l] = ft_strjoin(c_tmp, tmp->arg);
		if (c_tmp)
			free(c_tmp);
		if (!new[*l])
			return (-1);
	}
	return (1);
}

int	ft_creat_argv(t_parsing *parsing)
{
	t_cmd	*tmp;
	char	**new;
	char	*c_tmp;
	int		l;

	if (!parsing && parsing->argv)
		return (0);
	tmp = parsing->cmd;
	l = count_argv(parsing);
	new = (char **)malloc(sizeof(char *) * (l + 1));
	if (!new)
		return (-1);
	ft_set_null(new, l + 1);
	l = 0;
	while (tmp)
	{
		if (tmp->arg)
			if (ft_join_arg(tmp, new, &l) < 0)
				return (-1);
		tmp = tmp->next;
	}
	ft_free_argv(parsing->argv);
	parsing->argv = new;
	return (1);
}

int	count_argv(t_parsing *parsing)
{
	int		l;
	t_cmd	*tmp;

	if (!parsing)
		return (0);
	tmp = parsing->cmd;
	l = 0;
	while (tmp)
	{
		if (tmp->arg && !(tmp->flag & JOIN))
			l++;
		tmp = tmp->next;
	}
	return (l);
}

int	ft_creat_std(char **std, t_cmd *cmd)
{
	t_cmd	*tmp;
	char	*c_tmp;

	tmp = cmd;
	if (std && cmd)
	{
		*std = ft_strdup(cmd->arg);
		if (!*std && cmd->arg)
			return (-1);
	}
	else
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->arg)
			if (ft_join(std, tmp) < 0)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_creat_all_arg(t_parsing *parsing)
{
	if (ft_creat_argv(parsing) < 0)
		return (-1);
	if (ft_creat_std(&parsing->str_in, parsing->quote_in) < 0)
		return (-1);
	if (ft_creat_std(&parsing->str_out, parsing->quote_out) < 0)
		return (-1);
	if (ft_creat_std(&parsing->str_err, parsing->quote_err) < 0)
		return (-1);
	return (0);
}
