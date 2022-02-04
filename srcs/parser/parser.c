/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:20:53 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/04 19:51:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

int	is_redir(t_token *token)
{
	if (!token)
		return (0);
	if (token->type == TOKEN && ft_isnum(token->data))
	{
		if (token->next->type == CHAR_GREATER)
			return (1);
	}
	if (token->type == CHAR_GREATER || token->type == CHAR_LESSER)
		return (1);
	return (0);
}

char	**ft_realloc_args(char **args, int i)
{
	char	**tmp;
	int		j;

	j = 0;
	tmp = args;
	args = malloc(sizeof(char *) * (i + 2));
	while(j <= i)
	{
		args[j] = tmp[i];
		j++;
	}
	free(tmp);
	return (args);
}

char	**read_args(char *last)
{
	char	**args;
	char	**tmp;
	char	*line;
	int		i;
	int		size;

	i = 0;
	args = malloc(sizeof(char *));
	line = readline("heredoc> ");
	while (ft_strncmp(last, line, ft_strlen(last) + 1))
	{
		args[i] = line;
		args = ft_realloc_args(args, i);
		line = readline("heredoc> ");
		i++;
	}
	args[i] = 0;
	return (args);
}

char	**parse_args(t_token *tokenlist, t_lexer *lexerbuf, t_parsing *parsebuf)
{
	t_token	*token;
	char	**args;
	int		i;

	if (parsebuf->flag & DOUBLE_STDIN)
		return (read_args(parsebuf->str_in));
	token = tokenlist;
	args = malloc(sizeof(char *) * (lexerbuf->ntokens + 1));
	i = 0;
	while (token)
	{
		while (is_redir(token))
			token = skip_redir(token);
		if (!token || token->type == CHAR_PIPE || token->type == CHAR_NULL)
		{
			args[i] = NULL;
			return (args);
		}
		args[i] = ft_strdup(token->data);
		i++;
		token = token->next;
	}
	args[i] = NULL;
	return (args);
}

//returns -1 if malloc error
int	parse(t_lexer *lexerbuf, t_parsing	*parsebuf)
{
	parsebuf->flag = 0;
	parsebuf->str_in = parse_redir_in(lexerbuf->tokenlist, &parsebuf->flag);
	parsebuf->str_out = parse_redir_out(lexerbuf->tokenlist, &parsebuf->flag);
	parsebuf->str_err = parse_redir_err(lexerbuf->tokenlist, &parsebuf->flag);
	if (lexerbuf->tokenlist->type == TOKEN)
	{
		parsebuf->argv = parse_args(lexerbuf->tokenlist, lexerbuf, parsebuf);
		if (!parsebuf->argv)
			return (-1);
		parsebuf->path = check_cmd(parsebuf->argv[0], lexerbuf->path);
		if (!parsebuf->path)
			return (-1);
	}
	else
		parsebuf->argv = malloc(sizeof(char *));
	while (lexerbuf->tokenlist)
	{
		if (lexerbuf->tokenlist->type == CHAR_PIPE)
		{
			lexerbuf->tokenlist = lexerbuf->tokenlist->next;
			parsebuf->next = (t_parsing *)malloc(sizeof(t_parsing));
			return (parse(lexerbuf, parsebuf->next));
		}
		lexerbuf->tokenlist = lexerbuf->tokenlist->next;
	}
	return (1);
}

void	destroy_tokenlist(t_token *token)
{
	t_token	*tmp;
	while (token)
	{
		tmp = token->next;
		free(token);
		token = tmp;
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

//returns NULL in case of malloc error
t_parsing	*parse_init(char *line, char **env)
{
	t_lexer		lexerbuf;
	t_parsing	*parserbuf;
	t_token		*saved;

	lexerbuf.path = get_pathv(env);
	lexerbuf.tokenlist = malloc(sizeof(t_token));
	saved = lexerbuf.tokenlist;
	if (!lexerbuf.tokenlist || !lexerbuf.path)
		return (exit_parsing(&lexerbuf, saved));
	lexerbuf.j = 0;
	if (!lexer_build(line, ft_strlen(line), &lexerbuf))
		return (exit_parsing(&lexerbuf, saved));
	parserbuf = malloc(sizeof(t_parsing));
	if (!parse(&lexerbuf, parserbuf))
		return (NULL);
	return (parserbuf);
}
