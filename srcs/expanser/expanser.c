#include "minishell.h"

int	replace_var(t_term *term, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if(insert_var(term->env, &cmd[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}


int	expanser(t_term  *term, t_parsing *parsing)
{
	int	i;

	i = 0;
	while (parsing->argv[i]);
	return (0);
}
