/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:14 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/07 16:04:43 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	token_init(t_token *tok, int datasize)
{
	tok->data = malloc(datasize + 1);
	tok->data[0] = 0;
	tok->type = CHAR_NULL;
	tok->next = NULL;
}

int	getchartype(char c)
{
	if (c == '\'' )
		return (CHAR_QUOTE);
	if (c == '\"')
		return (CHAR_DQUOTE);
	if (c == '|')
		return (CHAR_PIPE);
	if (c == '&')
		return (CHAR_AMPERSAND);
	if (c == ' ')
		return (CHAR_WHITESPACE);
	if (c == ';')
		return (CHAR_SEMICOLON);
	if (c == '\\')
		return (CHAR_ESCAPESEQUENCE);
	if (c == '\t')
		return (CHAR_TAB);
	if (c == '\n')
		return (CHAR_NEWLINE);
	if (c == '>')
		return (CHAR_GREATER);
	if (c == '<')
		return (CHAR_LESSER);
	if (c == 0)
		return (CHAR_NULL);
	return (CHAR_GENERAL);
}

void	tokenize_general(t_lexer *lexerbuf, t_token *token, char *input
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
	if (lexerbuf->chtype == CHAR_WHITESPACE || lexerbuf->chtype
		== CHAR_SEMICOLON || lexerbuf->chtype == CHAR_GREATER
		|| lexerbuf->chtype == CHAR_LESSER || lexerbuf->chtype
		== CHAR_LESSER || lexerbuf->chtype == CHAR_AMPERSAND || lexerbuf
		->chtype == CHAR_PIPE)
		set_token_whitespace(token, &lexerbuf->j, size, lexerbuf->i);
}

int	lexer_build(char *input, int size, t_lexer *lexerbuf)
{
	t_token	*token;

	if (!lexerbuf)
		return (-1);
	if (size == 0)
	{
		lexerbuf->ntokens = 0;
		return (0);
	}
	token = lexerbuf->tokenlist;
	token_init(token, size);
	lexerbuf->state = STATE_GENERAL;
	lexerbuf->i = 0;
	while (1)
	{
		lexerbuf->c = input[lexerbuf->i++];
		lexerbuf->chtype = getchartype(lexerbuf->c);
		if (lexerbuf->state == STATE_GENERAL)
			tokenize_general(lexerbuf, token, input, size);
		if (lexerbuf->c == '\0')
			break ;
	}
}
