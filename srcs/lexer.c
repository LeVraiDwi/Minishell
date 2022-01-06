/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:14 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/06 21:13:05 by asaboure         ###   ########.fr       */
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

int	setTokenQuote(t_token *token, int *j)
{
	token->data[*j++] = CHAR_QUOTE;
	token->type = TOKEN;
	return (STATE_IN_QUOTE);
}

int	setTokenDquote(t_token *token, int *j)
{
	token->data[*j++] = CHAR_DQUOTE;
	token->type = TOKEN;
	return (STATE_IN_DQUOTE);
}

void	setTokenEscSeq(t_token *token, int *j, int *i, char *input)
{
	token->data[*j++] = input[*++i];
	token->type = TOKEN;
}

void	setTokenGeneral(t_token *token, int *j, char c)
{
	token->data[*j++] = c;
	token->type = TOKEN;
}

void	setTokenWhitespace(t_token *token, int *j, int size, int i)
{
	if (j > 0)
	{
		token->data[*j] = 0;
		token->next = malloc(sizeof(t_token));
		token = token->next;
		tok_init(token, size - i);
		*j = 0;
	}
}

int	lexer_build(char *input, int size, t_lexer *lexerbuf)
{
	int		i;
	int		j;
	char	c;
	int		chtype;
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
	i = 0;
	do
	{
		c = input[i++];
		chtype = getchartype(c);
		if (lexerbuf->state == STATE_GENERAL)
		{
			if (chtype == CHAR_QUOTE)
				lexerbuf->state = setTokenQuote(token, &j);
			if (chtype == CHAR_DQUOTE)
				lexerbuf->state = setTokenDquote(token, &j);
			if (chtype == CHAR_ESCAPESEQUENCE)
				setTokenEscSeq(token, &j, &i, input);
			if (chtype == CHAR_GENERAL)
				setTokenGeneral(token, &j, c);
			if (chtype == CHAR_WHITESPACE || chtype == CHAR_SEMICOLON || chtype
					== CHAR_GREATER || chtype == CHAR_LESSER || chtype
					== CHAR_LESSER || chtype == CHAR_AMPERSAND || chtype
					== CHAR_PIPE)
				setTokenWhitespace(token, &j, size, i);
		}
	} while (c != '\0');
}