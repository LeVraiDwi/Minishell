#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_term	term;
	char	*cmd[] = {"env", 0};
	char	*cmd1[] = {"export", "a=12", "jaime=", "pain=jamenfkfhssflf", "0"};

	(void)argv;
	(void)argc;
	ft_init_env(&term, env);
	ft_env(term, cmd);
	ft_export(&term, cmd1);
	ft_unset(&term, argv + 1);
	ft_env(term, cmd);
	return (0);
}
