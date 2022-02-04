#include "minishell.h"

int	ft_in_out(t_parsing *parsing)
{
	t_parsing *next;
	int		pipefd[2];

	next = parsing->next;
	if (parsing->out == STDOUT)
	{
		if(pipe(pipefd) < 0)
			return (-1);
		parsing->out = pipefd[1];
		if (!next->str_in)
			next->in = pipefd[0];
	}
	else if (!next->str_in)
		next->in = parsing->out;
	return (0);
}
