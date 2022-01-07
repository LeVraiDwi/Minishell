/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:48:48 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/07 18:50:41 by asaboure         ###   ########.fr       */
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
