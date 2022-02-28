#include "minishell.h"

t_cmd	**ft_creat_tab(t_cmd *cmd)
{
	t_cmd	**tab;
	
	tab = (t_cmd **)malloc(sizeof(t_cmd *) * (2));
	if (!tab)
		return (0);
	tab[0] = cmd;
	tab[1] = 0;
	return (tab);
}

t_cmd	**split_pipe(t_cmd *cmd)
{
	t_cmd	**tab;
	t_cmd	*first;
	int		l;
	
	tab = ft_creat_tab(cmd);
	if (!tab)
	{
		ft_free_cmd(cmd);
		return (0);
	}
	first = cmd;
	l = 0;
	while (tab[l])
	{
		while (cmd)
		{
			if (!(cmd->flag & IGNORE) && (cmd->flag & PIPE))
			{
				if (ft_split_tab(&tab) < 0)
				{
					ft_free_cmd_tab(tab);
					return (0);
				}
				cmd->next = 0;
			}
			cmd = cmd->next;
		}
		l++;
		cmd = tab[l];
	}
	return (tab);
}

int	ft_split_tab(t_cmd ***tab)
{
	t_cmd	**tmp;
	int		l;

	l = 0;
	while ((*tab)[l])
		l++;
	tmp = (t_cmd **)malloc(sizeof(t_cmd *) * (l + 2));
	if (!tmp)
		return (-1);
	tmp[l + 1] = 0;
	l = 0;
	while ((*tab)[l])
	{
		tmp[l] = (*tab)[l];
		l++;
	}
	free(*tab);
	*tab = tmp;
	return (0);
}

int	ft_free_cmd_tab(t_cmd **tab)
{
	int	l;

	l = 0;
	while (tab[l])
	{
		ft_free_cmd(tab[l]);
		tab[l] = 0;
		l++;
	}
	free(tab);
	return (-1);
}
