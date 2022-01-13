#include "minishell.h"

int	ft_is_valid_name(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_unset(t_term *term, char **cmd)
{
	int	l;
	int	flag;
	int	ret;

	l = 0;
	flag = 0;
	ret = 0;
	while (cmd[l])
	{
		if (ft_is_valid_name(cmd[l]))
		{
			ret = 0;
			remove_env(term, cmd[l]);
		}
		else if (!flag)
		{
			printf("unset: %s: invalide parameter name\n", cmd[l]);
			flag  = 1;
			ret = 1;
		}
		else
			ret = 1;
		l++;
	}
	return (ret);
}
