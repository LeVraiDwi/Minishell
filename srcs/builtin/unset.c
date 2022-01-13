#include "minishell.h"

int	ft_is_valid_name(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_isasnum(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

int	unset(t_term *term, char **cmd)
{
	int	l;
	int	flag;

	l = 0;
	flag = 0;
	while (cmd[l])
	{
		if (ft_is_valid_name(cmd[l]))
			remove_env(term, cmd[l]);
		else if (!flag)
		{
			printf("unset: %s: invalide parameter name\n");
			flag  = 1;
		}
		l++;
	}
}
