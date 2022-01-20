#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_term	term;
	char	*str;
	char	**cmd;
	int	i;
	//char	*cmd1[] = {"env", 0};
	//char	*cmd1[] = {"export", "a=12", "jaime=", "pain=jamenfkfhssflf", "0"};

	(void)argv;
	(void)argc;
	if(!init_term(&term, env))
		return (0);
	while (!term.exit)
	{
		str = readline("\033[34;01mMinishell\033[00m$ ");
		cmd = ft_split(str, ' ');
		i = ft_is_builtin(*cmd);
		printf("%d\n", i);
		if (i == 6)
			term.exit = 1;
		else if (i > 0)
			term.built[i](&term, cmd);
		free(str);
	}
	return (0);
}
