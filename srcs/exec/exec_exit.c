#include "minishell.h"

int	ft_make_exit(t_term *term, t_parsing *exec, t_cmd **cmd, int in_pipe)
{
	if (!in_pipe && ft_is_exit(exec))
		ft_exit(term, exec, cmd);
	return (0);
}
