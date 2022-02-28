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
	err = 130;
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