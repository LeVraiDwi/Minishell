#include "minishell.h"

int	parser(t_term *term, t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	if (split_quote(cmd) < 0)
		return (-1);
	if (split_spe_char(cmd) < 0)
		return (-1);
	printf("debut ahdoc\n");
	if (ahdoc(term, cmd) < 0)
		return (-1);
	printf("debut ahdoc\n");
	return (0);
}
