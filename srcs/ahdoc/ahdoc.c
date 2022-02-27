/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahdoc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:51:25 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/27 16:16:27 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_write_tab(t_term *term, t_cmd *cmd, t_cmd *tab)
{
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

int	ft_ahdoc(t_term *term, t_cmd *cmd, char *limiter)
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
	if (ft_write_tab(term, cmd, tab) < 0)
		ft_free_ahdoc(term, cmd, limiter, EXIT_FAILURE);
	ft_free_ahdoc(term, cmd, limiter, EXIT_SUCCESS);
	return (0);
}

int	ft_creat_ahdoc(t_term *term, t_cmd *cmd, char *limiter)
{
	int	child;
	int	status;

	status = 0;
	if (pipe(cmd->pipefd) < 0)
		return (-1);
	child = fork();
	if (child < 0)
		return (-1);
	else if (child == 0)
		ft_ahdoc(term, cmd, limiter);
	signal_handler_child();
	if (waitpid(0, &status, 0) < 0)
		return (-1);
	signal_handler();
	close(cmd->pipefd[1]);
	return (0);
}

char	*ft_is_ahdoc(t_cmd *cmd)
{
	t_cmd	*next;
	char	*limiter;

	if (!cmd || !cmd->next)
		return (0);
	next = cmd->next;
	if (next->flag & IS_SPE)
		return (0);
	limiter = ft_strdup(next->arg);
	if (!limiter)
		return (0);
	ft_add_flag(next, IGNORE);
	return (limiter);
}

int	ahdoc(t_term *term, t_cmd *cmd)
{
	char	*limiter;

	while (cmd)
	{
		if ((cmd->flag & DOUBLE_REDIR_IN) && !(cmd->flag & IGNORE))
		{
			limiter = ft_is_ahdoc(cmd);
			if (limiter)
				if (ft_creat_ahdoc(term, cmd, limiter) < 0)
					return (-1);
			if (limiter)
				free(limiter);
		}
		cmd = cmd->next;
	}
	return (0);
}
