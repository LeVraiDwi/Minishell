#ifndef ERR_H
# define ERR_H
# define SYNTAX_ERR 1
# define SYNTAX_STR "minishell: syntax error near unexpected token `"
int		ft_set_err(t_cmd *cmd, t_cmd *first, int err_num);
int		ft_set_syntax_err(t_cmd *cmd);
#endif
