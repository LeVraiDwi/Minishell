/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:58:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/26 18:58:03 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*parse_redir_out(t_token *token, int *flag)
{
	t_token	*saved;

	*flag = 0;
	saved = token;
	while (token)
	{
		if (token->type == CHAR_GREATER && !(saved && ft_strncmp(saved->data,
					"2", 2) == 0))
		{
			*flag = 1;
			if (token->next->type == CHAR_GREATER)
			{
				*flag = 2;
				return (token->next->next->data);
			}
			return (token->next->data);
		}
		saved = token;
		token = token->next;
	}
	return (NULL);
}

char	*parse_redir_in(t_token *token, int *flag)
{
	*flag = 0;
	while (token)
	{
		if (token->type == CHAR_LESSER)
		{
			*flag = 1;
			if (token->next->type == CHAR_LESSER)
			{
				*flag = 2;
				return (token->next->next->data);
			}
			return (token->next->data);
		}
		token = token->next;
	}
	return (NULL);
}

char	*parse_redir_err(t_token *token, int *flag)
{
	*flag = 0;
	while (token)
	{
		if (ft_strncmp(token->data, "2", 2) == 0)
		{
			if (token->next->type == CHAR_GREATER)
			{
				*flag = 1;
				if (token->next->next->type == CHAR_GREATER)
				{
					*flag = 2;
					return (token->next->next->next->data);
				}
				return (token->next->next->data);
			}
		}
		token = token->next;
	}
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
}
