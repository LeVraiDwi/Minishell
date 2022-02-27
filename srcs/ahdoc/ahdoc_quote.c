#include "minishell.h"

int	ft_is_ahdoc_quote(t_cmd *cmd)
{
	if ((cmd->flag & DOUBLE_QUOTE) || (CMD->FLAG & SIMPLE_QUOTE))
		return (1);
	return (0);
}
