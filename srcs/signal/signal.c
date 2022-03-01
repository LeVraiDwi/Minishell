/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:26:36 by asaboure          #+#    #+#             */
/*   Updated: 2022/03/01 21:14:54 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler_heredoc(int id)
{
	struct sigaction	heredoc_act;
	struct sigaction	parent_act;

	parent_act.sa_sigaction = signal_set_err;
	parent_act.sa_flags = SA_SIGINFO;
	sigemptyset(&parent_act.sa_mask);
	heredoc_act.sa_handler = SIG_DFL;
	heredoc_act.sa_flags = 0;
	sigemptyset(&heredoc_act.sa_mask);
	if (id != 0)
		sigaction(SIGINT, &parent_act, NULL);
	else
		sigaction(SIGINT, &heredoc_act, NULL);
}

void	signal_set_err(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
		g_err = 130;
}

void	signal_handler_child(int id)
{
	struct sigaction	child_act;
	struct sigaction	parent_act;
	struct sigaction	child_quit_act;

	child_act.sa_handler = SIG_DFL;
	child_act.sa_flags = 0;
	sigemptyset(&child_act.sa_mask);
	parent_act.sa_handler = SIG_IGN;
	parent_act.sa_flags = 0;
	sigemptyset(&parent_act.sa_mask);
	child_quit_act.sa_handler = SIG_DFL;
	child_quit_act.sa_flags = 0;
	sigemptyset(&child_quit_act.sa_mask);
	if (id != 0)
	{
		sigaction(SIGINT, &parent_act, NULL);
		sigaction(SIGQUIT, &parent_act, NULL);
	}
	else
	{
		sigaction(SIGINT, &child_act, NULL);
		sigaction(SIGQUIT, &child_quit_act, NULL);
	}
}

void	main_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGINT)
		newprompt(sig);
}

void	signal_handler(void)
{
	struct sigaction	main_act;
	struct sigaction	ignore_act;
	
	main_act.sa_sigaction = main_handler;
	main_act.sa_flags = SA_SIGINFO;
	sigemptyset(&main_act.sa_mask);
	ignore_act.sa_handler = SIG_IGN;
	ignore_act.sa_flags = 0;
	sigemptyset(&ignore_act.sa_mask);
	sigaction(SIGINT, &main_act, NULL);
	sigaction(SIGQUIT, &ignore_act, NULL);
}
