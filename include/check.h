#ifndef CHECK_H
# define CHECK_H
int		ft_check_redir(t_cmd *cmd);
int     ft_is_cmd(t_cmd *cmd);
int     ft_set_cmd(t_cmd *cmd);
int     ft_check_flag(t_cmd *cmd);
int     check_file(t_cmd *cmd);
int		ft_isdir(char *path);
#endif
