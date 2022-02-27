#include "minishell.h"

int	ft_close_exec(t_parsing *exec)
{
	ft_close(exec->pipe_in[0], exec->pipe_in[1]);
	ft_close(exec->pipe_out[0], exec->pipe_out[1]);
	return (-1);
}
