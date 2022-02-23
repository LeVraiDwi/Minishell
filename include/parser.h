/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:10:10 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/23 19:57:24 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define CMD 1
# define ARG 2
# define PIPE 4
# define SIMPLE_REDIR_OUT 8
# define DOUBLE_REDIR_OUT 16
# define SIMPLE_REDIR_IN 32
# define DOUBLE_REDIR_IN 64
# define SIMPLE_QUOTE 128
# define DOUBLE_QUOTE 256
# define VAR 512
# define LAST_RET 1024
# define HOME 2048
# define JOIN 4096
# define IGNORE 8192
# define IS_SPE 124 
# define IS_REDIR 120

int		parser(t_term *term, t_cmd *cmd);
int		ft_quote_len(char *str);
int		ft_type_quote(char c, int flag);
int		ft_split_quote(t_cmd **cmd, char type, int start, int flag);
int		split_quote(t_cmd *quote);
int		ft_do_quote(t_cmd **cmd, int i, int *l);
int		ft_is_special_char(char *cmd, int l, int flag);
int		ft_is_spe_var(char *cmd, int l, int flag);
int		ft_is_redir(char *str, int l, int flag);
int		ft_is_home(char *cmd, int l, int flag);
int		ft_add_new_cmd(t_cmd *cmd, char *tmp, int flag);
int		split_spe_char(t_cmd *cmd);
int		ft_split_var(t_cmd **cmd, int i);
int		ft_set_new_cmd(t_cmd *cmd, char *tmp, int start, int l);
int		ft_var_len(char *var);
int		ft_make_quote_flag(int old_flag, char type, int join, int first);
int		ft_len_spe(int flag);
int		ft_split_spe(t_cmd **comd, int start, int flag);
int		ft_make_var(t_term *term, t_cmd *tab);
int		ft_replace_in_tab(t_term *term, t_cmd *tab);
int		ft_ahdoc_var_len(char *str);
int		ft_free_ahdoc(t_term *term, t_cmd *cmd, char *str, int exit_state);
int		ft_write_tab(t_term *term, t_cmd *cmd, t_cmd *tab);
int		ft_ahdoc(t_term *term, t_cmd *cmd, char *limiter);
int		ft_creat_ahdoc(t_term *term, t_cmd *cmd, char *limiter);
int		ahdoc(t_term *term, t_cmd *cmd);
int		ft_check_redir(t_cmd *cmd);
int		ft_next_or_replace(t_cmd **comd, char *tmp, int start, int l);
int		ft_is_interprete(t_cmd *cmd, int flag);
int		ft_split_quote_spe(t_cmd *cmd, int flag, int *i);
int		ft_add_or_next(t_cmd **comd, char *tmp, int i, int l);
int		ft_make_replace(t_term *term, t_cmd *tab, int *i);
void	ft_set_flag(t_cmd *cmd, t_cmd *new);
void	ft_add_flag(t_cmd *cmd, int flag);
t_cmd	*ft_next_cmd(t_cmd *cmd);
char	ft_is_quote(char c);
char	*ft_is_ahdoc(t_cmd *cmd);
#endif
