#ifndef ENV_H
# define ENV_H

typedef struct s_term t_term;

int	ft_init_env(t_term *term, char **env);
int	ft_is_env_var(char *env, char *var);
int	ft_is_env(char **env, char *var);
int	ft_realloc_env(t_term *term, char *var);
int	add_env(t_term *term, char *var);
int	ft_free_env(char **env);
int	replace_env(t_term *term, char *var, int i);
int	ft_dealloc_env(t_term *term, int i);
int	remove_env(t_term *term, char *var);
void	print_env(t_term term);
int	ft_update_pwd(t_term *term, char *path);

#endif
