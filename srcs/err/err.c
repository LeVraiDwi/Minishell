#include "minishell.h"

int	ft_set_err(t_cmd *cmd, t_cmd *first, int err_num)
{
	(void)first;
	if (err_num == SYNTAX_ERR)
		return (ft_set_syntax_err(cmd));
	return (0);
}

int	ft_set_syntax_err(t_cmd *cmd)
{
	t_cmd	*next;
	char	str[1];

	next = (t_cmd *)cmd->next;
	if (next)
		str[0] = next->arg[0];
	if (!cmd->next)
		write(2, "minishell: syntax error near unexpected token `new line'\n", 58);
	else
	{
		write (2, SYNTAX_STR, ft_strlen(SYNTAX_STR));
		write (2, str, 1);
		write (2, "\'\n", 2);
	}
	return (-1);
}
