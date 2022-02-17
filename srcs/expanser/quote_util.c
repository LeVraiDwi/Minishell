#include "minishell.h"

int	make_quote(t_parsing *parsing)
{
	int		i;

	i = 0;
	while(parsing)
	{
		if (ft_creat_cmd(parsing))
			return (-1);
		if (split_quote(parsing->cmd))
			return (-1);
		if (ft_make_cmd(parsing->str_in, &parsing->quote_in))
			return (-1);
		if (split_quote(parsing->quote_in))
			return (-1);
		if (ft_make_cmd(parsing->str_out, &parsing->quote_out))
			return (-1);
		if (split_quote(parsing->quote_out))
			return (-1);
		if (ft_make_cmd(parsing->str_err, &parsing->quote_err))
			return (-1);
		if (split_quote(parsing->quote_err))
			return (-1);
		parsing = parsing->next;
	}
	return (0);
}
