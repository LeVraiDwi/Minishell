#include "minishell.h"

int	ft_open_std_cmd(t_term *term, t_cmd *cmd)
{
	t_cmd	*next;

	while (cmd)
	{
		next = (t_cmd *)cmd->next;
		if ((cmd->flag & IS_REDIR) && !(cmd->flag & DOUBLE_REDIR_IN))
		{
			ft_add_flag(next, IGNORE);
			if (next)
				if (ft_stdopen(term, cmd, next->arg) < 0)
					return (-1);
		}
		cmd = next;
	}
	return (0);
}

int	creat_exec(t_term *term, t_cmd *cmd, t_parsing **exec)
{
	(void)exec;
	if (ft_open_std_cmd(term, cmd) < 0)
		return (0);
	return (0);
}
