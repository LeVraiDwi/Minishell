#ifndef BUILT_H
# define BUILT_H
# define FLAG_N 1
typedef struct s_term t_term;

int	is_flag(char *arg);
void	ft_echo_new_line(int flag);
int	ft_is_var(char *var);
int	ft_is_valid_name(char *cmd);
int	ft_cmd_length(char **cmd);
int	ft_env(t_term term, char **cmd);
int	ft_export(t_term *term, char **cmd);
int	ft_unset(t_term *term, char **cmd);
int	ft_pwd(char **cmd);
int	ft_echo(char **cmd);
int	ft_cd(char **cmd);
#endif
