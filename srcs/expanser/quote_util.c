/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:57:25 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 18:09:24 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_quote(t_parsing *parsing)
{
	int		i;

	i = 0;
	while (parsing)
	{
		if (ft_creat_cmd(parsing))
			return (-1);
		if (split_quote(parsing->cmd))
			return (-1);
		if (ft_make_cmd(parsing->str_in, &parsing->quote_in))
			return (-1);
		if (split_quote(parsing->quote_in))
			return (-1);
		if (ft_make_cmd(parsing->str_out, &parsing->quote_out))
			return (-1);
		if (split_quote(parsing->quote_out))
			return (-1);
		if (ft_make_cmd(parsing->str_err, &parsing->quote_err))
			return (-1);
		if (split_quote(parsing->quote_err))
			return (-1);
		parsing = parsing->next;
	}
	return (0);
}

int	ft_set_new_cmd(t_cmd *cmd, char *tmp, int start, int l)
{
	t_cmd	*new;

	new = ft_init_cmd();
	if (!new)
		return (-1);
	ft_add_next_cmd(cmd, new);
	new->arg = ft_substr(tmp, start, l);
	if (!new->arg)
		return (-1);
	new->flag = cmd->flag;
	if (!(cmd->flag & JOIN))
		new->flag += JOIN;
	return (0);
}

int	ft_split_var(t_cmd *cmd, int i)
{
	int		l;
	char	*tmp;
	t_cmd	*new;

	l = ft_var_len(cmd->arg + i + 1);
	if (l)
	{
		tmp = cmd->arg;
		cmd->arg = ft_substr(cmd->arg, 0, i);
		if (!cmd->arg)
			return (ft_free((void **)&tmp));
		if (ft_set_new_cmd(cmd, tmp, i, l + 1) < 0)
			return (ft_free((void **)&tmp));
		if (ft_set_new_cmd((t_cmd *)cmd->next,
				tmp, i + l + 1, ft_strlen(tmp + i + l + 1)) < 0)
			return (ft_free((void **)&tmp));
		free(tmp);
	}
	return (0);
}
