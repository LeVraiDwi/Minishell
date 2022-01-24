#ifndef EXPANSER_H
# define EXPANSER_H
# define CHAR_SPE "$~"
# define IS_VAR 1
# define is_home 2

int		ft_var_len(char *var);
int		ft_is_special_char(char c);
int		insert_var(char **cmd, int var_start);
char	*ft_insertvar(char *s, char *str, int var_start, int var_l);
int		replace_var(char **cmd);
int		expanser(t_term *term, t_parsing *parsing);
#endif
