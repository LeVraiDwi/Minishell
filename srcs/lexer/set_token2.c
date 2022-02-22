/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:32:38 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/22 19:32:53 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*set_token_separator(t_token *token, t_lexer *lexerbuf, int size)
{
	token = set_token_whitespace(token, &lexerbuf->j, size, lexerbuf->i);
	if (!token)
		return (NULL);
	token->data[0] = lexerbuf->chtype;
	token->data[1] = 0;
	token->type = lexerbuf->chtype;
	token->next = malloc(sizeof(t_token));
	if (!token->next)
		return (NULL);
	token = token->next;
	token_init(token, size - lexerbuf->i);
	if (!token->data)
		return (NULL);
	return (token);
}
