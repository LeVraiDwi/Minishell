#include "minishell.h"

void print_env(t_term term)
{
	int	i;

	i = 0;
	while (term->env[i])
	{
		printf("%s\n", term->env[i])
		i++;
	}
}
