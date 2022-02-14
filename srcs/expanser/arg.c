#include "minishell.h"

int     ft_creat_argv(t_parsing *parsing)
{
        t_cmd   *tmp;
	char	**new;
	char	*c_tmp;
	int	l;

        if (!parsing && parsing->argv)
                return (0);
        tmp = parsing->cmd;
	l = count_argv(parsing);
	new = (char **)malloc(sizeof(char *) * (l + 1));
	if (!new)
		return (-1);
	ft_bzero((void *)new, l);
	l = 0;
        while (tmp)
        {
                if (tmp->arg)
		{
			if (!(tmp->flag & JOIN))
			{
				if (new[l])
					l++;
				new[l] = ft_strdup(tmp->arg);
				if (!new[l])
					return (-1);
			}
			else
			{
				c_tmp = new[l];
				new[l] = ft_strjoin(c_tmp, tmp->arg);
				if (!new[l])
					return (-1);
			}
		}
		tmp = tmp->next;
        }
	ft_free_argv(parsing->argv);
	parsing->argv = new;
	return (1);
}

int	count_argv(t_parsing *parsing)
{
	t_cmd	*tmp;
	int	l;

	if (!parsing)
		return (0);
	tmp = parsing->cmd;
	l = 0;
	while (tmp)
	{
		if (tmp->arg && !(tmp->flag & JOIN))
			l++;
		tmp = tmp->next;
	}
	return (l);
}
