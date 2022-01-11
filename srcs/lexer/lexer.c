/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:14 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/10 16:09:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "libft.h"

char	**get_pathv(char **env)
{
	int		i;
	char	**path;

	while(env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + ft_strlen("PATH="), ':');
			return (path);
		}
		i++;
	}
	return (NULL);
}

//TODO: Protect mallocs 
int	lexer_build(char *input, int size, t_lexer *lexerbuf)
{
	t_token	*token;
	int		k;

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
	token = lexerbuf->tokenlist;
	k = 0;
	while (token)
	{
		
		if (token->type == TOKEN)
		{
			char *pathv;
			if (getpathv(env))
			{

			}
		}
		token = token->next;
	}
}
