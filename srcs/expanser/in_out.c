#include "minishell.h"

int	ft_in_out(t_parsing *parsing, int *pipefd)
{
	t_parsing *next;

	next = parsing->next;
	if (parsing->out == STDOUT && !next->str_in)
	{
		parsing->out = pipefd[1];
		next->in = pipefd[0];
	}
	return (0);
}
