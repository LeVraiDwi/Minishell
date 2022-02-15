#include "minishell.h"

t_cmd	*ft_init_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!new)
		return (0);
	new->next = 0;
	new->flag = 0;
	new->arg = 0;
	return (new);
}

int	ft_free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->next)
			ft_free_cmd(cmd->next);
		if (cmd->arg)
		{
			free(cmd->arg);
			cmd->arg = 0;
		}
		free(cmd);
	}
	cmd = 0;
	return (-1);
}

int	ft_add_end_cmd(t_cmd **first, t_cmd *new)
{
	t_cmd	*tmp;

	if (!*first)
	{
		*first = new;
		return (1);
	}
	tmp = *first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

void	ft_add_next_cmd(t_cmd *cmd, t_cmd *new)
{
	t_cmd *tmp;

	tmp = cmd->next;
	cmd->next = new;
	new->next = tmp;
}

int	ft_creat_cmd(t_parsing *parsing)
{
	int	i;
	t_cmd	*new;

	i = 0;
	while (parsing->argv[i])
	{
		new = ft_init_cmd();
		if (!new)
			return (ft_free_cmd(parsing->cmd));
		ft_add_end_cmd(&parsing->cmd, new);
		new->arg = ft_strdup(parsing->argv[i]);
		if (!new->arg)
			return (ft_free_cmd(parsing->cmd));
		i++;
	}
	return (0);
}
