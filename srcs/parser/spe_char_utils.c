#include "minishell.h"

int	ft_len_spe(int flag)
{
	if (flag & HOME || flag & PIPE)
		return (1);
	if (flag & LAST_RET)
		return (2);
	if (flag & DOUBLE_REDIR_IN || flag & DOUBLE_REDIR_OUT)
		return (2);
	if (flag & SIMPLE_REDIR_IN || flag & SIMPLE_REDIR_OUT)
		return (1);
	return (0);
}
