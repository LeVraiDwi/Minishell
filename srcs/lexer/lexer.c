/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:14 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/26 19:03:42 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "libft.h"
#include <unistd.h>

void	ft_strjoin_free(char **str, char *buf)
{
	char	*tmp;

	if (*str == NULL)
		*str = ft_strdup(buf);
	else if (**str == '\0')
	{
		free(*str);
		*str = ft_strdup(buf);
	}
	else
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, buf);
		free(tmp);
	}
}

char	**get_pathv(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + ft_strlen("PATH="), ':');
			i = -1;
			while (path[++i])
				ft_strjoin_free(&(path[i]), "/");
			return (path);
		}
		i++;
	}
	return (NULL);
}

//counts the number of valid paths and increments ntokens
// int	count_paths(char **path,  char *cmd)
// {
// 	int		i;
// 	char	*pathcmd;

// 	i = 0;
// 	while (path[i])
// 	{
// 		pathcmd = ft_strjoin(path[i], cmd);
// 		if (!pathcmd)
// 			return (0);
// 		if (access(pathcmd, X_OK | F_OK) == 0)
// 			lexerbuf->ntokens++;
// 		free(pathcmd);
// 		i++;
// 	}
// 	return (i);
// }

char	*check_cmd(char *input, char **path)
{
	int		i;
	char	*pathcmd;

	i = 0;
	if (access(input, X_OK | F_OK) == 0)
		return (ft_strdup(input));
	while (path[i])
	{
		pathcmd = ft_strjoin(path[i], input);
		if (!pathcmd)
			return (NULL);
		if (access(pathcmd, X_OK | F_OK) == 0)
			return (pathcmd);
		free(pathcmd);
		i++;
	}
	return (NULL);
}

int	count_tokens(t_token *token)
{
	int	i;

	i = 0;
	while (token)
	{
		i++;
		token = token->next;
	}
	return (i);
}

//TODO: Protect mallocs 
int	lexer_build(char *input, int size, t_lexer *lexerbuf)
{
	t_token	*token;

	if (!lexerbuf)
		return (0);
	lexerbuf->ntokens = 0;
	if (size == 0)
		return (0);
	token = lexerbuf->tokenlist;
	token_init(token, size);
	if (!token->data)
		return (0);
	if (!tokenize(lexerbuf, token, size, input))
		return (0);
	token = lexerbuf->tokenlist;
	lexerbuf->ntokens = count_tokens(token);
	return (1);
}

int	lexer_error(t_token *token)
{
	char	*data;

	data = "newline";
	if (token)
		data = token->data;
	printf("syntax error near unexpected token `");
	printf("%s", data);
	printf("'\n");
	return (0);
}

int	lexer_check(t_lexer *lexerbuf)
{
	t_token *current;
	t_token *previous;

	current = lexerbuf->tokenlist;
	previous = NULL;
	while (current)
	{
		if (current->type == CHAR_PIPE)
		{
			if (!previous || previous->type != TOKEN)
				return (lexer_error(current));
		}
		previous = current;
		current = current->next;
	}
	// if (previous && (previous->type != TOKEN && previous->type != CHAR_PIPE))
	// 	return (lexer_error(current));
	return (1);
}