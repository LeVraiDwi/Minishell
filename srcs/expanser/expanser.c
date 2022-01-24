#include "minishell.h"

int	replace_var(char **cmd)
{
	int	i;
	int	l;

	i = 0;
	while (cmd[i])
	{
		l = 0;
		while (cmd[i][l])
		{
			if (ft_is_special_char(cmd[i][l]))
			{
				l = insert_var(cmd + i, l);
				if (l < 0)
					return (-1);
			}
			l++;
		}
		i++;
	}
	return (0);
}


int	expanser(t_term  *term, t_parsing *parsing)
{
	int	i;

	i = 0;
	while (parsing->argv[i]);
	return (0);
}
