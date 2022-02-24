#ifndef PIPE_H
# define PIPE_H

int		ft_get_new_cmd(char **str);
int		ft_creat_new_pipe(t_cmd **cmd);
int		ft_is_valid_cmd(char *str);
int		ft_get_cmd(int *pipefd);
int		ft_split_tab(t_cmd ***tab, t_cmd *first);
int		ft_free_cmd_tab(t_cmd **tab);
char	*ft_get_str_pipe(int *pipefd);
t_cmd	**ft_creat_tab(t_cmd *cmd);
t_cmd	**split_pipe(t_cmd *cmd);
#endif