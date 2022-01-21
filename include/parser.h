/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:20:44 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/21 17:30:42 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"
# include "lexer.h"

int		ft_isnum(char *str);
char	*parse_redir_in(t_token *token, int *flag);
char	*parse_redir_err(t_token *token, int *flag);
char	*parse_redir_out(t_token *token, int *flag);
char	*check_cmd(char *input, char **path);
int		parse(t_lexer *lexerbuf, t_parsing	*parsebuf);

#endif