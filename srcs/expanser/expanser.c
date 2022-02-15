#include "minishell.h"

int	replace_var(t_term *term, t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!parsing)
		return (0);
	if (ft_replace_cmd(term, parsing->cmd) < 0)
		return (-1);
	if (ft_replace_cmd(term, parsing->quote_in) < 0)
		return (-1);
	if (ft_replace_cmd(term, parsing->quote_out) < 0)
		return (-1);
	if (ft_replace_cmd(term, parsing->quote_err) < 0)
		return (-1);
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
		tmp->cmd = 0;
		tmp->quote_in = 0;
		tmp->quote_out = 0;
		tmp->quote_err = 0;
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
	if (make_quote(parsing))
		return (-1);
	while (tmp)
	{
		if (replace_var(term, tmp) < 0)
			return (-1);
		if (ft_creat_all_arg(tmp) < 0)
			return (-1);
		if (tmp->next)
			if(ft_setfilename(tmp) < 0)
				return (-1);
		ft_free_cmd(tmp->cmd);
		ft_free_cmd(tmp->quote_in);
		ft_free_cmd(tmp->quote_out);
		ft_free_cmd(tmp->quote_err);
		tmp = tmp->next;
	}
	return (0);
}
