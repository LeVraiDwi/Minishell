#include "minishell.h"

int	ft_open_std_cmd(t_cmd *cmd)
{
	t_cmd	*next;

	while (cmd)
	{
		next = (t_cmd *)cmd->next;
		if ((cmd->flag & IS_REDIR) && !(cmd->flag & DOUBLE_REDIR_IN))
		{
			ft_add_flag(next, IGNORE);
			if (next)
				if (ft_stdopen(cmd, next->arg) < 0)
					return (-1);
		}
		cmd = next;
	}
	return (0);
}

int	ft_join(t_parsing *exec, t_cmd *cmd)
{
	char	*str;

	while (cmd)
	{
		if ((cmd->flag & ARG) && !(cmd->flag & IGNORE) && !(cmd->flag & JOIN))
		{
			str = ft_get_next(cmd);
			if (!str)
				return (-1);
			if (ft_add_to_tab_cmd(exec, str) < 0)
				return (-1);
		}
		else if ((cmd->flag & IS_REDIR) && !(cmd->flag & IGNORE))
			ft_add_redir(exec, cmd);
		cmd = (t_cmd *)cmd->next;
	}
	return (0);
}

int	creat_exec(t_term * term, t_cmd *cmd, t_parsing **exec)
{	
	if (expanser(term, cmd))
	if (ft_open_std_cmd(cmd) < 0)
		return (-1);
	*exec = ft_creat_pars();
	if (!*exec)
		return (0);
	if (ft_join(*exec, cmd) < 0)
		return (0);
	return (0);
}