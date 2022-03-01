/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:26:36 by asaboure          #+#    #+#             */
/*   Updated: 2022/03/01 17:14:47 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler_heredoc(int id)
{
	struct sigaction	heredoc_act;

	heredoc_act.sa_handler = SIG_DFL;
	heredoc_act.sa_flags = 0;
	sigemptyset(&heredoc_act.sa_mask);
	if (id != 0)
		signal(SIGINT, sigint_set_err);
	else
		sigaction(SIGINT, &heredoc_act, NULL);
}

void	sigint_set_err(int sig)
{
	(void)sig;
	g_err = 130;
}

void	signal_handler_child(int id)
{
	struct sigaction	child_act;
	struct sigaction	parent_act;

	child_act.sa_handler = SIG_DFL;
	child_act.sa_flags = 0;
	sigemptyset(&child_act.sa_mask);
	parent_act.sa_handler = SIG_IGN;
	parent_act.sa_flags = 0;
	sigemptyset(&parent_act.sa_mask);
	if (id != 0)
	{
		signal(SIGINT, sigint_set_err);
		sigaction(SIGQUIT, &parent_act, NULL);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		sigaction(SIGQUIT, &child_act, NULL);
	}
}

void	signal_handler(void)
{
	struct sigaction	main_act;

	main_act.sa_handler = SIG_IGN;
	main_act.sa_flags = 0;
	sigemptyset(&main_act.sa_mask);
	signal(SIGINT, newprompt);
	sigaction(SIGQUIT, &main_act, NULL);
}
