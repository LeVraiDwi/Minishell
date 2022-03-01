/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:28:10 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 15:09:29 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# define STD_IN 0
# define STD_OUT 1

int		ft_error_pipe(t_parsing *cmd);
int		ft_launch_exec(t_term *term,
			t_parsing **exec, int *pipefd, t_cmd **tab);
int		ft_make_exit(t_term *term, t_parsing *exec, t_cmd **tab, t_parsing *pars);
void	ft_wait_child(int nb_fork);
int		ft_child(t_term *term, t_parsing *cmd, int last_child);
int		exec(t_term *term, t_cmd **tab);
int		ft_exec_builtin(t_term *term, t_parsing *parsing, int exec, t_cmd *cmd);
int		redir_flux(t_parsing *cmd, int last_child);
int		define_flags(int flag, int std);
int		ft_setflux(t_parsing *cmd);
int		ft_isfile(char *path);
int		ft_checkright(char *path, int right);
int		ft_openfile(char *path, int right, int mode, int flag);
int		ft_stdopen(t_cmd *cmd, char *path);
int		ft_open_std_cmd(t_cmd *cmd);
int		creat_exec(t_term *term, t_cmd *cmd, t_parsing **exec, int *pipefd);
int		ft_add_to_tab_cmd(t_parsing *exec, char *str);
int		ft_add_redir(t_parsing *exec, t_cmd *cmd);
int		ft_get_path(t_term *term, t_parsing *exec);
int		ft_init_pipe_out(t_parsing *exec, int *pipefd);
int		ft_exec(t_term *term, t_parsing *exec);
int		ft_close_exec(t_parsing *exec);
int		ft_is_exit(t_parsing *exec);
int		ft_set_pipe(t_parsing *exec, int *pipefd, t_cmd *next);
int		ft_select_built_exec(t_term *term,
			t_parsing *exec, int in_pipe, t_cmd *next);
void	signal_handler_child(int child);
void	sigint_set_err(int sig);
void	ft_set_pipe_in(t_parsing *exec, int *pipe);
void	ft_select_std(t_parsing *execc, t_cmd *next);
void	ft_dup_pipe(int *olf, int *new);
char	**get_pathv(char **env);
char	*check_cmd(char *input, char **path);
char	*ft_get_next(t_cmd *cmd);
#endif
