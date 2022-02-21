#include "minishell.h"

int	parser(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	if (split_quote(cmd) < 0)
		return (-1);
	return (0);
}
