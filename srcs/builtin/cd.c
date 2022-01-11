#include "minishell.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		strerror(E2BIG);
		return (1);
	}
	if(chdir(argv[1]) < 0)
	{
		perror("Error:");
		return (1);
	}
	return (0);
}
