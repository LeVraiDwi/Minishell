#include "minishell.h"

int	ft_in_out(t_parsing *parsing)
{
	t_parsing *next;
	int	pipefd[2];

	if (pipe(pipefd) < 0)
		return (-1);
	next = parsing->next;
	if (parsing->out == STDOUT && !next->str_in)
	{
		parsing->out = pipefd[1];
		next->in = pipefd[0];
	}
	return (0);
}
