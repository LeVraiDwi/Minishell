/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:10:10 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/21 17:21:59 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
int		ft_skip_space(char *str, int start);
int		new_cmd(t_cmd **new, char *str, int *l, int *i);
int		new_cmd_quote(char *str, int i);
int		ft_free_lexer(t_cmd *cmd, char *str, char *tmp);
t_cmd	*lexer(char *str);
#endif
