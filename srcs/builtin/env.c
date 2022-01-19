#include "minishell.h"

int	ft_env(t_term term, char **cmd)
{
	printf("%p\n", cmd[1]);
	if (!strisstr(cmd[0], "env") || cmd[1])
	{
		strerror(E2BIG);
		return (1);
	}
	print_env(term);
	return (0);
}
