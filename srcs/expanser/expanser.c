#include "minishell.h"

int	replace_var(t_term *term, char **cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (cmd[i])
	{
		if(insert_var(term->env, &cmd[i]) < 0)
			return (-1);
		printf("%s\n", cmd[i]);
		i++;
	}
	return (0);
}

int	ft_stdopen(char *path, int *fd, int flags, int right)
{
	*fd = ft_openfile(path, flags, right);
	if (*fd < 0)
		return (-1);
	return (0);
}

int	expanser(t_term  *term, t_parsing *parsing)
{
	int	i;

	i = 0;
	while (parsing)
	{
		if(replace_var(term, parsing->argv) < 0)
			return (-1);
		if (parsing->str_in)
			if (ft_stdopen(parsing->str_in, &parsing->in, parsing->flag, O_RDONLY) < 0)
				return (-1);
		if (parsing->str_out)
			if (ft_stdopen(parsing->str_out, &parsing->out, O_TRUNC, O_RDWR) < 0)
				return (-1);
		if (parsing->str_err)
			if (ft_stdopen(parsing->str_err, &parsing->err, parsing->flag, O_RDWR) < 0)
				return (-1);
		if (parsing->next)
		if	(ft_in_out(parsing) < 0)
			return (-1);
		parsing = parsing->next;
	}
	return (0);
}
