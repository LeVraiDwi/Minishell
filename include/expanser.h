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
#endif
