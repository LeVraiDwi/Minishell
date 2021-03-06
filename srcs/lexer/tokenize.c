/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:53:21 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/22 19:34:30 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include <stdlib.h>

t_token	*tokenize_general(t_lexer *lexerbuf, t_token *token, char *input
	, int size)
{
	if (lexerbuf->chtype == CHAR_QUOTE)
		lexerbuf->state = set_token_quote(token, &lexerbuf->j);
	if (lexerbuf->chtype == CHAR_DQUOTE)
		lexerbuf->state = set_token_dquote(token, &lexerbuf->j);
	if (lexerbuf->chtype == CHAR_ESCAPESEQUENCE)
		set_token_esc_seq(token, &lexerbuf->j, &lexerbuf->i, input);
	if (lexerbuf->chtype == CHAR_GENERAL)
		set_token_general(token, &lexerbuf->j, lexerbuf->c);
	if (lexerbuf->chtype == CHAR_WHITESPACE)
		token = set_token_whitespace(token, &lexerbuf->j, size, lexerbuf->i);
	if (is_separator(lexerbuf->chtype))
		token = set_token_separator(token, lexerbuf, size);
	return (token);
}

void	tokenize_in_dquote(t_lexer *lexerbuf, t_token *token)
{
	token->data[lexerbuf->j++] = lexerbuf->c;
	if (lexerbuf->chtype == CHAR_DQUOTE)
		lexerbuf->state = STATE_GENERAL;
}

void	tokenize_in_quote(t_lexer *lexerbuf, t_token *token)
{
	token->data[lexerbuf->j++] = lexerbuf->c;
	if (lexerbuf->chtype == CHAR_QUOTE)
		lexerbuf->state = STATE_GENERAL;
}

void	tokenize_null(t_lexer *lexerbuf, t_token *token)
{
	token->data[lexerbuf->j] = 0;
	lexerbuf->j = 0;
}

int	tokenize(t_lexer *lexerbuf, t_token *token, int size, char *input)
{
	lexerbuf->state = STATE_GENERAL;
	lexerbuf->i = 0;
	while (1)
	{
		lexerbuf->c = input[lexerbuf->i++];
		lexerbuf->chtype = getchartype(lexerbuf->c);
		if (lexerbuf->state == STATE_GENERAL)
			token = tokenize_general(lexerbuf, token, input, size);
		else if (lexerbuf->state == STATE_IN_DQUOTE)
			tokenize_in_dquote(lexerbuf, token);
		else if (lexerbuf->state == STATE_IN_QUOTE)
			tokenize_in_quote(lexerbuf, token);
		if (!token)
			return (0);
		if (lexerbuf->chtype == CHAR_NULL && lexerbuf->j > 0)
			tokenize_null(lexerbuf, token);
		if (lexerbuf->c == '\0')
			break ;
	}
	return (1);
}
