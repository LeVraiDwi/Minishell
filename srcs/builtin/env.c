#include "minishell.h"

int	ft_env(t_term *term, char **cmd)
{
	if (cmd[1])
	{
		strerror(E2BIG);
		return (1);
	}
	print_env(*term);
	return (0);
}
