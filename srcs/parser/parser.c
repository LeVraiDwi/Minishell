#include "minishell.h"

int	parser(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	if (split_quote(cmd) < 0)
		return (-1);
	ft_print_cmd(cmd);
	if (split_spe_char(cmd) < 0)
		return (-1);
	return (0);
}
