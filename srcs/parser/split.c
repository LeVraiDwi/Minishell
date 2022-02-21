#include "minishell.h"

int     ft_var_len(char *var)
{
	int     i;

	i = 0;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return (i);
}

t_cmd	*ft_next_cmd(t_cmd *cmd)
{
	if (cmd->next)
		return ((t_cmd *)(((t_cmd *)cmd->next)->next));
	else
		return (cmd->next);
}

int	split_spe_char(t_cmd *cmd)
{
	int	i;
	int	flag;

	while (cmd)
	{
		i = 0;
		while (cmd->arg && cmd->arg[i])
		{
			flag = ft_is_special_char(cmd->arg, i, cmd->flag);
			printf("flag:%d, %c\n", flag, cmd->arg[i]);
			if (flag & VAR)
				if (ft_split_var(&cmd, i) < 0)
					return (-1);
			flag = 0;
			i++;
		}
		cmd = cmd->next;
	}
	return (0);
}

int     ft_split_var(t_cmd **comd, int i)
{
        int             l;
        char    *tmp;
	t_cmd	*cmd;

	cmd = *comd;
        l = ft_var_len(cmd->arg + i + 1);
        if (l)
        {
                tmp = cmd->arg;
                cmd->arg = ft_substr(cmd->arg, 0, i);
                if (!cmd->arg)
                        return (ft_free((void **)&tmp));
		if (*cmd->arg)
		{		
			if (ft_set_new_cmd(cmd, tmp, i, l + 1) < 0)
				return (ft_free((void **)&tmp));
			cmd = cmd->next;
		}
		else
		{
                	cmd->arg = ft_substr(cmd->arg, 0, i);
			if (!cmd->arg)
				return (0);
		}
		if (tmp[i + l + 1])
		{
			if (ft_set_new_cmd((t_cmd *)cmd->next,
				tmp, i + l + 1, ft_strlen(tmp + i + l + 1)) < 0)
				return (ft_free((void **)&tmp));
		}
		free(tmp);
		*comd = cmd;
        }
        return (0);
}

void	ft_set_flag(t_cmd *cmd, t_cmd *new)
{
        if (!(cmd->flag & JOIN))
                new->flag += JOIN;
	if ((cmd->flag & DOUBLE_QUOTE) && !(new->flag & DOUBLE_QUOTE))
                new->flag += DOUBLE_QUOTE;
	if ((cmd->flag & SIMPLE_QUOTE) && !(new->flag & SIMPLE_QUOTE))
                new->flag += SIMPLE_QUOTE;

}

int     ft_set_new_cmd(t_cmd *cmd, char *tmp, int start, int l)
{
        t_cmd   *new;

        new = ft_init_cmd();
        if (!new)
                return (-1);
        ft_add_next_cmd(cmd, new);
        new->arg = ft_substr(tmp, start, l);
        if (!new->arg)
                return (-1);
	ft_set_flag(cmd, new);
        return (0);
}
