/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:58:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/26 18:10:18 by asaboure         ###   ########.fr       */
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

int	is_redir(t_token *token)
{
	if (!token)
		return (0);
	if (token->type == TOKEN && ft_isnum(token->data))
	{
		if (token->next && token->next->type == CHAR_GREATER)
			return (1);
	}
	if (token->type == CHAR_GREATER || token->type == CHAR_LESSER)
		return (1);
	return (0);
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

void	*exit_parsing(t_lexer *lexerbuf, t_token *token)
{
	if (lexerbuf->path)
		free_split(lexerbuf->path);
	free(lexerbuf->path);
	if (token)
		destroy_tokenlist(token);
	return (NULL);
}

char	**ft_realloc_args(char **args, int i)
{
	char	**tmp;
	int		j;

	j = 0;
	tmp = args;
	args = malloc(sizeof(char *) * (i + 2));
	while (j <= i)
	{
		args[j] = tmp[i];
		j++;
	}
	free(tmp);
	return (args);
}
