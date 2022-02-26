#include "minishell.h"

int	redir_flux(t_parsing *cmd, int last_child)
{
	int	status;

	status = 0;
	if (last_child != 0)
		waitpid(last_child, &status, 0);
	if (cmd->in != STDIN)
		if (dup2(cmd->in, STDIN) < 0)
			return (ft_error_pipe(cmd));
	if (cmd->out != STDOUT)
		if (dup2(cmd->out, STDOUT) < 0)
			return (ft_error_pipe(cmd));
	return (0);
}
