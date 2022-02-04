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

int	ft_set_redir(t_parsing *parsing)
{
	t_parsing	*next;

	next = parsing->next;
	if (parsing->str_out && !next->str_in)
	{
		next->str_in = ft_strdup(parsing->str_out);
		if (!next->str_in)
			return (-1);
	}
	return (0);
}
