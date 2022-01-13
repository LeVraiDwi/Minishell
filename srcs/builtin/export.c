#include "minishell.h"

int	ft_is_var(char *var)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (!var)
		return (0);
	while (var[i] && ft_isalnum(var[i]))
		i++;
	if (var[i] == '=')
		return (1);
	return (0);
}

int	export(t_term *term, char **cmd)
{
	int	l;
	int	flag;

	l = 1;
	flag = 0;
	while (cmd[l])
	{
		if (ft_is_var(cmd[l]))
			add_env(term, cmd[l]);
		else if (!flag)
		{
			printf("export: %s: invalide parameter name\n");
			flag  = 1;
		}
		l++;
	}
	return (0);
}
