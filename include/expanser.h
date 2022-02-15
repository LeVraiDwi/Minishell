#ifndef EXPANSER_H
# define EXPANSER_H
# define CHAR_SPE "$~"
# define HOME "HOME"

int		ft_var_len(char *var);
int		ft_is_special_char(char *cmd, int l);
int		insert_var(char **env, char **cmd);
char		*ft_insertvar(char *s, char *str, int var_start, int var_l);
int		replace_var(t_term *term, t_parsing *parsing);
int		expanser(t_term *term, t_parsing *parsing);
int		ft_stdopen(char *path, int *fd, int flags, int right);
int		ft_isfile(char *path);
int		ft_checkright(char *path, int right);
int		ft_openfile(char *path, int flags, int right);
int		ft_in_out(t_parsing *parsing);
int		ft_setfilename(t_parsing *parsing);
int		ft_setstd(t_parsing *parsing);
char		ft_is_quote(char c);
int		ft_quote_len(char *str);
int		ft_type_quote(char c);
int		ft_split_quote(t_cmd *cmd, int len_q, char type, int start);
int		split_quote(t_cmd *quote);
int		ft_replace_cmd(t_term *term, t_cmd *cmd);
int		ft_creat_argv(t_parsing *parsing);
int		count_argv(t_parsing *parsing);
int		ft_creat_all_arg(t_parsing *parsing);
int		ft_creat_std(char **std, t_cmd *cmd);
int		make_quote(t_parsing *parsing);
#endif
