#include "minishell.h"

char	*ft_get_next(t_cmd *cmd)
{
	char	*new;
	char	*tmp;
	
	new = ft_strdup(cmd->arg);
	if (!new)
		return (0);
	cmd = (t_cmd *)cmd->next;
	while (cmd && (cmd->flag & JOIN))
	{
		if ((cmd->flag & ARG) && !(cmd->flag & IGNORE))
		{
			tmp = new;
			new = ft_strjoin(new, cmd->arg);
			free(tmp);
			if (!new)
				return (0);
		}
		cmd = (t_cmd *)cmd->next;
	}
	return (new);
}

int	ft_add_to_tab_cmd(t_parsing *exec, char *str)
{
	int		l;
	char	**new;

	l = 0;
	while (exec->argv && exec->argv[l])
		l++;
	new = (char **)malloc(sizeof(char *) * (l + 2));
	if (!new)
		return (-1);
	new[l + 1] = 0;
	l = 0;
	while (exec->argv && exec->argv[l])
	{
		new[l] = exec->argv[l];
		l++;
	}
	new[l] = str;
	l = 0;
	if (exec->argv)
		free(exec->argv);
	exec->argv = new;
	return (0);
}

int	ft_add_redir(t_parsing *exec, t_cmd *cmd)
{
	if ((cmd->flag & SIMPLE_REDIR_OUT) || (cmd->flag & DOUBLE_REDIR_OUT))
	{
		if (exec->out > 1)
			close(exec->out);
		exec->out = cmd->pipefd[0];
	}
	else if ((cmd->flag & SIMPLE_REDIR_IN) || (cmd->flag & DOUBLE_REDIR_IN))
	{
		if (exec->in > 1)
			close(exec->in);
		exec->in = cmd->pipefd[0];
	}
	return (0);
}
