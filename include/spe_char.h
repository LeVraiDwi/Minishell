#ifndef SPE_CHAR_H
# define SPE_CHAR_H
int		ft_is_interprete(t_cmd *cmd, int flag);
int		ft_len_spe(int flag);
int		ft_is_special_char(char *cmd, int l, int flag);
int		ft_is_spe_var(char *cmd, int l, int flag);
int		ft_is_redir(char *str, int l, int flag);
int		ft_is_home(char *cmd, int l, int flag);
#endif
