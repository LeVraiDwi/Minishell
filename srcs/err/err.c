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

char	*ft_creat_err_msg(char *arg, int err)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(arg, ": ");
	if (!tmp)
		return (0);
	new = ft_strjoin(tmp, strerror(err));
	if (tmp)
		free(tmp);
	if (!new)
		return (0);
	return (new);
}

int	ft_add_err(t_term *term, char *str)
{
	int		l;
	char	**new;

	l = 0;
	while (term->err && term->err[l])
		l++;
	new = (char **)malloc(sizeof(char *) * (l + 2));
	if (!new)
		return (-1);
	new[l + 1] = 0;
	l = 0;
	while (term->err && term->err[l])
	{
		new[l] = term->err[l];
		l++;
	}
	new[l] = str;
	if (term->err)
		free(term->err);
	term->err = new;
	return (0);
}

int	ft_error_std(t_term *term, t_cmd *cmd, int err)
{
	t_cmd	*next;
	char	*str;

	next = (t_cmd *)cmd->next;
	str = ft_creat_err_msg(next->arg, err);
	if (!str)
		return (-1);
	if (ft_add_err(term, str) < 0)
		return (ft_free((void **)str));
	term->is_err = 1;
	return (-1);
}
