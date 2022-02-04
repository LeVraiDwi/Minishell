/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:53:21 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/27 17:49:18 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include <stdlib.h>

int	set_token_quote(t_token *token, int *j)
{
	token->data[(*j)++] = CHAR_QUOTE;
	token->type = TOKEN;
	return (STATE_IN_QUOTE);
}

int	set_token_dquote(t_token *token, int *j)
{
	token->data[(*j)++] = CHAR_DQUOTE;
	token->type = TOKEN;
	return (STATE_IN_DQUOTE);
}

void	set_token_esc_seq(t_token *token, int *j, int *i, char *input)
{
	token->data[(*j)++] = input[++(*i)];
	token->type = TOKEN;
}

void	set_token_general(t_token *token, int *j, char c)
{
	token->data[(*j)++] = c;
	token->type = TOKEN;
}

t_token	*set_token_whitespace(t_token *token, int *j, int size, int i)
{
	if (*j > 0)
	{
		token->data[*j] = 0;
		token->next = malloc(sizeof(t_token));
		if (!token->next)
			return (NULL);
		token = token->next;
		token_init(token, size - i);
		if (!token->data)
			return (NULL);
		*j = 0;
	}
	return (token);
}
