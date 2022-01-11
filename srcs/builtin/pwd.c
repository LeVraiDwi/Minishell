#include "minishell.h"

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		strerror(E2BIG);
		return (1);
	}
	return (0);
}
