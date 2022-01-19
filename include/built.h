#ifndef BUILT_H
# define BUILT_H
# define FLAG_N 1
# define CD 0
# define PWD 1
# define EXPORT 2
# define UNSET 3
# define ENV 4
# define ECHO 5

typedef struct s_term t_term;

int	is_flag(char *arg);
void	ft_echo_new_line(int flag);
int	ft_is_var(char *var);
int	ft_is_valid_name(char *cmd);
int	ft_cmd_length(char **cmd);
int	ft_env(t_term term, char **cmd);
int	ft_export(t_term *term, char **cmd);
int	ft_unset(t_term *term, char **cmd);
int	ft_pwd(t_term *term, char **cmd);
int	ft_echo(t_term *term, char **cmd);
int	ft_cd(t_term *term, char **cmd);
int	ft_is_builtin(char *cmd);
#endif
