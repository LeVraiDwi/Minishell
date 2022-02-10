/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:58:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/10 15:23:01 by asaboure         ###   ########.fr       */
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

char	*parse_redir_out(t_token *token, unsigned int *flag)
{
	t_token	*saved;

	saved = token;
	while (token && token->type != CHAR_PIPE)
	{
		if (token->type == CHAR_GREATER && !(saved && ft_strncmp(saved->data,
					"2", 2) == 0))
		{
			if (token->next->type == CHAR_GREATER)
			{
				*flag += DOUBLE_STDOUT;
				return (token->next->next->data);
			}
			*flag += SIMPLE_STDOUT;
			return (token->next->data);
		}
		saved = token;
		token = token->next;
	}
	return (NULL);
}

char	*parse_redir_in(t_token *token, unsigned int *flag)
{
	while (token && token->type != CHAR_PIPE)
	{
		if (token->type == CHAR_LESSER)
		{
			if (token->next->type == CHAR_LESSER)
			{
				*flag += DOUBLE_STDIN;
				return (token->next->next->data);
			}
			*flag += SIMPLE_STDIN;
			return (token->next->data);
		}
		token = token->next;
	}
	return (NULL);
}

char	*parse_redir_err(t_token *token, unsigned int *flag)
{
	while (token && token->type != CHAR_PIPE)
	{
		if (ft_strncmp(token->data, "2", 2) == 0)
		{
			if (token->next->type == CHAR_GREATER)
			{
				if (token->next->next->type == CHAR_GREATER)
				{
					*flag += DOUBLE_STDERR;
					return (token->next->next->next->data);
				}
				*flag += SIMPLE_STDERR;
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
