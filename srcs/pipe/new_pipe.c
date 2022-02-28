#include "minishell.h"

int	ft_is_valid_cmd(char *str)
{
	if (!str || !*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (str)
		return (1);
	return (0);
}

t_cmd	*new_pipe(t_cmd *cmd)
{
	t_cmd	*next;

	next  = (t_cmd *)cmd->next;
	cmd->next = 0;
	return (next);
}
