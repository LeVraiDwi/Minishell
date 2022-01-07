/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:14 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/07 18:57:39 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

//TODO: Protect mallocs 
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
	tokenize(lexerbuf, token, size, input);
}
