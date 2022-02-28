/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:26:36 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 18:26:57 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler_heredoc(int id)
{
	struct sigaction	heredoc_act;

	heredoc_act.sa_handler = SIG_DFL;
	sigemptyset(&heredoc_act.sa_mask);
	if (id != 0)
		signal(SIGINT, sigint_set_err);
	else
		sigaction(SIGINT, &heredoc_act, NULL);
}

void	sigint_set_err(int sig)
{
	(void)sig;
	printf("\n");
	g_err = 130;
}

void	signal_handler_child(int id)
{
	if (id != 0)
	{
		signal(SIGINT, sigint_set_err);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	signal_handler(void)
{
	signal(SIGINT, newprompt);
	signal(SIGQUIT, SIG_IGN);
}