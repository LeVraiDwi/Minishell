#include "minishell.h"

int	ft_make_cmd(char *str, t_cmd **cmd)
{
	t_cmd	*new;

	if (str)
	{
		new = ft_init_cmd();
		if (!new)
			return (-1);
		new->arg = ft_strdup(str);
		if (!new->arg)
		{
			free(new);
			return (-1);
		}
		*cmd = new;
	}
	return (0);
}

void	ft_print_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		printf("cmd:%s|\n", cmd->arg);
		cmd = cmd->next;
	}
	return;
}
