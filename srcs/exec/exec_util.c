#include "minishell.h"

int	redir_flux(t_parsing *cmd, int last_child)
{
/*	int	status;

	status = 0;
	if (last_child != 0)
		waitpid(last_child, &status, 0);*/
	if (cmd->in != STDIN)
		if (dup2(cmd->in, STDIN) < 0)
			return (ft_error_pipe(cmd));
	if (cmd->out != STDOUT)
		if (dup2(cmd->out, STDOUT) < 0)
			return (ft_error_pipe(cmd));
	return (0);
}

int	define_flags(int flag, int std)
{
	if ((flag & DOUBLE_STDOUT) && std == STDOUT)
		return (O_APPEND);
	if ((flag & DOUBLE_STDERR) && std == STDERR)
		return (O_APPEND);
	if ((flag & SIMPLE_STDOUT) && std == STDOUT)
		return (O_TRUNC);
	if ((flag & SIMPLE_STDERR) && std == STDERR)
		return (O_TRUNC);
	return (0);
}

int	ft_setflux(t_parsing *cmd, int *pipefd)
{
	if (cmd->str_in)
		if (ft_stdopen(cmd->path, &cmd->in, 0, O_RDONLY) < 0)
			return (-1);
	if (cmd->str_out)
		if (ft_stdopen(cmd->path, &cmd->out, define_flags(cmd->flag, STDOUT), O_RDWR) < 0)
			return (-1);
	if (cmd->str_err)
		if (ft_stdopen(cmd->path, &cmd->err, define_flags(cmd->flag, STDOUT), O_RDWR) < 0)
			return (-1);
	if (cmd->next)
		if (ft_in_out(cmd, pipefd) < 0)
			return (-1);
	return (0);
}
