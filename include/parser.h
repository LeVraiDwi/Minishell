/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:44 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/26 18:58:19 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"
# include "lexer.h"

typedef struct s_parsing	t_parsing;

int			ft_isnum(char *str);
char		*parse_redir_in(t_token *token, int *flag);
char		*parse_redir_err(t_token *token, int *flag);
char		*parse_redir_out(t_token *token, int *flag);
char		*check_cmd(char *input, char **path);
int			parse(t_lexer *lexerbuf, t_parsing	*parsebuf);
t_parsing	*parse_init(char *line, char **env);
t_token		*skip_lesser(t_token *token);
t_token		*skip_greater(t_token *token);
t_token		*skip_redir(t_token *token);
char		**parse_args(t_token *tokenlist, t_lexer *lexerbuf);
void		free_split(char **split);
#endif
