#include "minishell.h"

int	ft_is_var(char *var)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (!var)
		return (0);
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	if (var[i] == '=')
		return (1);
	return (0);
}

int	ft_export(t_term *term, char **cmd)
{
	int	l;
	int	flag;
	int	ret;

	l = 1;
	flag = 0;
	ret = 0;
	while (cmd[l])
	{
		if (ft_is_var(cmd[l]))
		{
			ret = 0;
			add_env(term, cmd[l]);
		}
		else if (!flag)
		{
			ret = 1;
			printf("export: %s: invalide parameter name\n", cmd[l]);
			flag  = 1;
		}
		else
			ret = 1;
		l++;
	}
	return (0);
}
