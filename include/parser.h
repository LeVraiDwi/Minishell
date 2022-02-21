/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:10:10 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/21 18:45:06 by tcosse           ###   ########.fr       */
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

int		parser(t_cmd *cmd);
int		ft_quote_len(char *str);
int		ft_type_quote(char c, int flag);
int		ft_split_quote(t_cmd *cmd, int len_q, char type, int start);
int		split_quote(t_cmd *quote);
int		ft_do_quote(t_cmd **cmd, int i, int *l);
int		ft_is_special_char(char *cmd, int l, int flag);
int		ft_is_spe_var(char *cmd, int l);
int		ft_is_redir(char *str, int l);
int		ft_is_home(char *cmd, int l, int flag);
int		ft_add_new_cmd(t_cmd *cmd, char *tmp, int start, int len_q);
char	ft_is_quote(char c);
#endif
