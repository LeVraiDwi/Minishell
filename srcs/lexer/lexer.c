/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:06:14 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/18 18:43:10 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "libft.h"
#include <unistd.h>

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
			return (path);
		}
		i++;
	}
	return (NULL);
}

//counts the number of valid paths and increments ntokens
int	count_paths(char **path, t_token *token, t_lexer *lexerbuf)
{
	int		i;
	char	*pathcmd;

	i = 0;
	while (path[i])
	{
		pathcmd = ft_strjoin(path[i], token->data);
		if (!pathcmd)
			return (0);
		if (access(pathcmd, X_OK | F_OK) == 0)
			lexerbuf->ntokens++;
		free(pathcmd);
		i++;
	}
	return (i);
}

char	**check_cmd(char **path, t_token *token, t_lexer *lexerbuf)
{
	int		i;
	int		j;
	char	*pathcmd;
	char	**cmd;

	i = count_paths(path, token, lexerbuf);
	cmd = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cmd)
		return (0);
	i = 0;
	j = 0;
	while (path[i])
	{
		pathcmd = ft_strjoin(path[i], token->data);
		if (!pathcmd)
			return (0);
		if (access(pathcmd, X_OK | F_OK) == 0)
			cmd[j++] = ft_strdup(pathcmd);
		free(pathcmd);
		i++;
	}
	if (j == 0)
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

void	strip_quotes(t_token *token)
{
	char	*dest;
	int		i;
	int		j;
	char	lastquote;
	char	c;

	dest = malloc(ft_strlen(token->data) + 1);
	if (ft_strlen(token->data) <= 1)
		return ;
	i = -1;
	j = 0;
	lastquote = 0;
	while (++i < (int)ft_strlen(token->data))
	{
		c = token->data[i];
		if ((c == '\'' || c == '\"') && lastquote == 0)
			lastquote = 0;
		else if (c == lastquote)
			lastquote = 0;
		else
			dest[j++] = c;
	}
	dest[j] = 0;
	free(token->data);
	token->data = dest;
}

int	count_tokens(t_token *token)
{
	int	i;

	i = 0;
	while(token)
	{
		i++;
		token = token->next;
	}
	return (i);
}

//TODO: Protect mallocs 
void	lexer_build(char *input, int size, t_lexer *lexerbuf)
{
	t_token	*token;
//	t_token	*saved;
//	char	**cmd;
//	int		i;

	if (!lexerbuf)
		return ;
	lexerbuf->ntokens = 0;
	if (size == 0)
		return ;
	token = lexerbuf->tokenlist;
	token_init(token, size);
	tokenize(lexerbuf, token, size, input);
	token = lexerbuf->tokenlist;
	lexerbuf->ntokens = count_tokens(token);
	/******************************* pas ici mdr ******************************/
	// while (token)
	// {
	// 	if (token->type == TOKEN)
	// 	{
	// 		cmd = check_cmd(lexerbuf->path, token, lexerbuf);
	// 		if (cmd)
	// 		{
	// 			saved = token->next;
	// 			free(token->data);
	// 			token->data = ft_strdup(cmd[0]);
	// 			i = 1;
	// 			while (i < lexerbuf->ntokens)
	// 			{
	// 				token->next = malloc(sizeof(t_token));
	// 				token_init(token->next, ft_strlen(cmd[i]));
	// 				token = token->next;
	// 				token->type = TOKEN;
	// 				token->data = ft_strdup(cmd[i]);
	// 				i++;
	// 			}
	// 			token->next = saved;
	// 		}
	// 		else
	// 		{
	// 			strip_quotes(token);
	// 			lexerbuf->ntokens++;
	// 		}
	// 	}
	// 	token = token->next;
	// }

	/******************************* pas ici mdr ******************************/
}
