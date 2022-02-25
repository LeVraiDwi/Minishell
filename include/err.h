#ifndef ERR_H
# define ERR_H
# define SYNTAX_ERR 1
# define SYNTAX_STR "minishell: syntax error near unexpected token `"
int		ft_set_err(t_cmd *cmd, t_cmd *first, int err_num);
int		ft_set_syntax_err(t_cmd *cmd);
int     ft_error_std(t_term *term, t_cmd *cmd, int err);
int		ft_add_err(t_term *term, char *str);
char	*ft_creat_err_msg(char *arg, int err);
void	print_err(t_term *term);
#endif
