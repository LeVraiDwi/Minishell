#include "minishell.h"

void	ft_add_flag(t_cmd *cmd, int flag)
{
	if (cmd && !(cmd->flag & flag))
		cmd->flag += flag;
}

int	ft_split_spe(t_cmd **comd, int start ,int flag)
{
	int		l;
	char	*tmp;
	t_cmd	*cmd;

	l = ft_len_spe(flag);
	cmd = *comd;
	if (l)
	{
		tmp = cmd->arg;
		cmd->arg = ft_substr(cmd->arg, 0, start);
		if (!cmd->arg)
			return (ft_free((void **)&tmp));
		if (*cmd->arg)
		{
			if (ft_set_new_cmd(cmd, tmp, start, l) < 0)
				return (ft_free((void **)&tmp));
			cmd = cmd->next;
		}
		else
		{
			if (cmd->arg)
				free(cmd->arg);
			cmd->arg = ft_substr(tmp, start, l);
			if (!cmd->arg)
				return (ft_free((void **)&tmp));
		}
		ft_add_flag(cmd, flag);	
		if (tmp[start + l])
		{
			if (ft_set_new_cmd(cmd, tmp, start + l, ft_strlen(tmp + start + l)) < 0)
				return (ft_free((void **)&tmp));
		}
		free(tmp);
		*comd = cmd;
	}
	return (0);
}
