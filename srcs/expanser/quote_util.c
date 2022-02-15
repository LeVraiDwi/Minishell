#include "minishell.h"

int	make_quote(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (ft_creat_cmd(parsing))
		return (-1);
	printf("cmd%d\n", i++);
	if (split_quote(parsing->cmd))
		return (-1);
	printf("cmd%d\n", i++);
	if (ft_make_cmd(parsing->str_in, &parsing->quote_in))
		return (-1);
	printf("cmd%d\n", i++);
	if (split_quote(parsing->quote_in))
		return (-1);
	printf("cmd%d\n", i++);
	if (ft_make_cmd(parsing->str_out, &parsing->quote_out))
		return (-1);
	printf("cmd%d\n", i++);
	if (split_quote(parsing->quote_out))
		return (-1);
	printf("cmd%d\n", i++);
	if (ft_make_cmd(parsing->str_err, &parsing->quote_err))
		return (-1);
	printf("cmd%d\n", i++);
	if (split_quote(parsing->quote_err))
		return (-1);
	printf("cmd%d\n", i++);
	return (0);
}
