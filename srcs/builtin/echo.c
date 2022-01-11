#include "minishell.h"

int	is_flag(char *arg)
{
	if (!arg || ft_strlen(arg) != 2)
		return (0);
	if (arg[0] == '-' && arg[1] == 'n')
		return (FLAG_N);
	return (0);
}

void	ft_echo_new_line(int flag)
{
	if (flag != FLAG_N)
		write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	flag;
	int	i;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	else if (argc > 1)
		flag = is_flag(argv[1]);
	if (flag)
		i = 2;
	else
		i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
		if (i < argc)
			write(1, " ", 1);
	}
	ft_echo_new_line(flag);
	return (0);
}
