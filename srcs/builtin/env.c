#include "minishell.h"

int	env(t_term term, char **cmd)
{
	if (!strisstr(*cmd, "env") || cmd[1])
	{
		strerror(E2BIG);
		return (1);
	}
	print_env(term);
	return (0);
}
