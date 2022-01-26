/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:20:53 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/26 18:51:29 by asaboure         ###   ########.fr       */
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

char	**parse_args(t_token *tokenlist, t_lexer *lexerbuf)
{
	t_token	*token;
	char	**args;
	int		i;

	token = tokenlist;
	args = malloc(sizeof(char *) * (lexerbuf->ntokens + 1));
	i = 0;
	while (token)
	{
		token = skip_redir(token);
		if (!token || token->type == CHAR_PIPE)
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

int	parse(t_lexer *lexerbuf, t_parsing	*parsebuf)
{
	parsebuf->str_in = parse_redir_in(lexerbuf->tokenlist, &parsebuf->in);
	parsebuf->str_out = parse_redir_out(lexerbuf->tokenlist, &parsebuf->out);
	parsebuf->str_err = parse_redir_err(lexerbuf->tokenlist, &parsebuf->err);
	if (lexerbuf->tokenlist->type == TOKEN)
	{
		parsebuf->argv = parse_args(lexerbuf->tokenlist, lexerbuf);
		parsebuf->path = check_cmd(parsebuf->argv[0], lexerbuf->path);
	}
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
	return (0);
}

void	*exit_parsing(t_lexer *lexerbuf)
{
	free_split(lexerbuf->path);
	free(lexerbuf->path);
	free(lexerbuf->tokenlist);
	return (NULL);
}

t_parsing	*parse_init(char *line, char **env)
{
	t_lexer		lexerbuf;
	t_parsing	*parserbuf;

	lexerbuf.path = get_pathv(env);
	lexerbuf.tokenlist = malloc(sizeof(t_token));
	lexerbuf.j = 0;
	if (!lexer_build(line, ft_strlen(line), &lexerbuf))
		return (exit_parsing(&lexerbuf));
	parserbuf = malloc(sizeof(t_parsing));
	parse(&lexerbuf, parserbuf);
	return (parserbuf);
}
