#ifndef EXEC_H
# define EXEC_H
int	ft_error_pipe(t_parsing *cmd);
void	ft_close(t_parsing *cmd);
int	ft_child(t_term *term, t_parsing *cmd, int last_child);
int	exec(t_term *term, t_parsing *cmd);
int	ft_exec_builtin(t_term *term, t_parsing *parsing);
int	redir_flux(t_parsing *cmd, int last_child);
#endif
