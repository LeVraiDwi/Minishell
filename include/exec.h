#ifndef EXEC_H
# define EXEC_H
int	ft_error_pipe(t_parsing *cmd);
int	ft_child(t_term *term, t_parsing *cmd, int last_child);
int	exec(t_term *term, t_cmd **tab);
int	ft_exec_builtin(t_term *term, t_parsing *parsing, int exec);
int	redir_flux(t_parsing *cmd, int last_child);
int	define_flags(int flag, int std);
int	ft_setflux(t_parsing *cmd);
int ft_isfile(char *path);
int ft_checkright(char *path, int right);
int ft_openfile(char *path, int right, int mode, int flag);
int ft_stdopen(t_term *term, t_cmd *cmd, char *path);
int ft_open_std_cmd(t_term *term, t_cmd *cmd);
int	creat_exec(t_term *term, t_cmd *cmd, t_parsing **exec);
int	ft_add_to_tab_cmd(t_parsing *exec, char *str);
int	ft_add_redir(t_parsing *exec, t_cmd *cmd);
char	*ft_get_next(t_cmd *cmd);
#endif
