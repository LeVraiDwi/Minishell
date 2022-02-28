/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahdoc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:51:25 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 01:55:22 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_write_tab(t_term *term, t_cmd *cmd, t_cmd *tab, int quote)
{
	if (!quote)
		if (ft_make_var(term, tab) < 0)
			return (-1);
	while (tab)
	{
		write(cmd->pipefd[1], tab->arg, ft_strlen(tab->arg));
		write(cmd->pipefd[1], "\n", 1);
		tab = tab->next;
	}
	return (0);
}

int	ft_ahdoc(t_term *term, t_cmd *cmd, char *limiter, int quote)
{
	t_cmd	*tab;
	char	*str;

	str = readline("> ");
	if (!str)
		ft_free_ahdoc(term, cmd, limiter, EXIT_FAILURE);
	while (!strisstr(limiter, str))
	{
		if (ft_creat_cmd(&tab, str) < 0)
			ft_free_ahdoc(term, cmd, limiter, EXIT_FAILURE);
		free(str);
		str = readline("> ");
		if (!str)
			ft_free_ahdoc(term, cmd, limiter, EXIT_FAILURE);
	}
	free(str);
	if (ft_write_tab(term, cmd, tab, quote) < 0)
		ft_free_ahdoc(term, cmd, limiter, EXIT_FAILURE);
	ft_free_ahdoc(term, cmd, limiter, EXIT_SUCCESS);
	return (0);
}

int	ft_creat_ahdoc(t_term *term, t_cmd *cmd, char *limiter, int quote)
{
	int	child;
	int	status;

	status = 0;
	if (pipe(cmd->pipefd) < 0)
		return (-1);
	child = fork();
	if (child < 0)
		return (-1);
	signal_handler_child(child);
	if (child == 0)
		ft_ahdoc(term, cmd, limiter, quote);
	if (waitpid(0, &status, 0) < 0)
		return (-1);
	signal_handler();
	close(cmd->pipefd[1]);
	return (0);
}

int	ft_is_ahdoc(t_cmd *cmd, char **lim)
{
	t_cmd	*next;
	char	*limiter;
	char	*tmp;
	int		flag;

	if (!cmd)
		return (-1);
	flag = 0;
	if ((cmd->flag & SIMPLE_QUOTE) || (cmd->flag & DOUBLE_QUOTE))
		flag = 1;
	limiter = ft_strdup(cmd->arg);
	if (!limiter)
		return (0);
	ft_add_flag(cmd, IGNORE);
	next = (t_cmd *)cmd->next;
	while (next && (next->flag & JOIN) && !(next->flag & IGNORE) && !(next->flag & IS_REDIR))
	{
		tmp = limiter;
		limiter = ft_strjoin(limiter, next->arg);
		printf("%s\n", limiter);
		free(tmp);
		if (!limiter)
			return (-1);
		ft_add_flag(next, IGNORE);
		if ((cmd->flag & SIMPLE_QUOTE) || (cmd->flag & DOUBLE_QUOTE))
			flag = 1;
		next = (t_cmd *)next->next;
	}
	*lim = limiter;
	return (flag);
}

int	ahdoc(t_term *term, t_cmd *cmd)
{
	char	*limiter;
	int		quote;

	while (cmd)
	{
		if ((cmd->flag & DOUBLE_REDIR_IN) && !(cmd->flag & IGNORE))
		{
			quote = ft_is_ahdoc((t_cmd *)cmd->next, &limiter);
			if (quote >= 0)
			{
				if (ft_creat_ahdoc(term, cmd, limiter, quote) < 0)
					return (-1);
			if (limiter)
				free(limiter);
			}
			else
				return (ft_set_err(cmd, SYNTAX_ERR));
			limiter = 0;
		}
		cmd = cmd->next;
	}
	return (0);
}
