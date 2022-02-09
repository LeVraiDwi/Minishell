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

int	ft_setstd(t_parsing *parsing)
{
	t_parsing *tmp;

	tmp = parsing;
	while (tmp)
	{
		tmp->in = STDIN;
		tmp->out = STDOUT;
		tmp->err = STDERR;
		tmp = tmp->next;
	}
	return (0);
}

int	expanser(t_term  *term, t_parsing *parsing)
{
	int	i;
	t_parsing	*tmp;

	i = 0;
	tmp = parsing;
	ft_setstd(parsing);
	while (tmp)
	{
		if(replace_var(term, tmp->argv) < 0)
			return (-1);
		if(replace_var(term, &tmp->str_in) < 0)
			return (-1);
		if(replace_var(term, &tmp->str_out) < 0)
			return (-1);
		if(replace_var(term, &tmp->str_err) < 0)
			return (-1);
		if (tmp->next)
			if(ft_setfilename(parsing) < 0)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
}
