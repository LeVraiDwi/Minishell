#ifndef EXPANSER_H
# define EXPANSER_H
# define CHAR_SPE "$~"
# define HOME "HOME"

int		ft_var_len(char *var);
int		ft_is_special_char(char *cmd, int l);
int		insert_var(char **env, char **cmd);
char		*ft_insertvar(char *s, char *str, int var_start, int var_l);
int		replace_var(t_term *term, char **cmd);
int		expanser(t_term *term, t_parsing *parsing);
int		ft_stdopen(char *path, int *fd, int flags, int right);
int		ft_isfile(char *path);
int		ft_checkright(char *path, int right);
int		ft_openfile(char *path, int flags, int right);
void		ft_in_out(t_term *term, t_parsing *parsing);
#endif
