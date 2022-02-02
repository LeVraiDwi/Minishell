#include "minishell.h"

void	ft_in_out(t_term *term, t_parsing *parsing)
{
	t_parsing *next;

	next = parsing->next;
	if (parsing->out == STDOUT)
	{
		parsing->out = term->pipefd[1];
		if (!next->str_in)
			next->in = term->pipefd[0];
	}
	else if (!next->str_in)
		next->in = parsing->out;
}
