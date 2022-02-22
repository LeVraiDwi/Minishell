/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:43:25 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/22 19:46:24 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*skip_lesser(t_token *token)
{
	if (token->next->type == CHAR_LESSER)
		return (token->next->next);
	return (token->next);
}

t_token	*skip_greater(t_token *token)
{
	if (token->next->type == CHAR_GREATER)
		return (token->next->next);
	return (token->next);
}

t_token	*skip_redir(t_token *token)
{
	if (token->type == TOKEN && ft_isnum(token->data))
	{
		if (token->next->type == CHAR_GREATER)
			return (skip_greater(token->next)->next);
	}
	if (token->type == CHAR_GREATER)
		return (skip_greater(token)->next);
	if (token->type == CHAR_LESSER)
		return (skip_lesser(token)->next);
	return (token);
}
