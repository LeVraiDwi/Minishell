/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:20:53 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/22 20:17:35 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**read_args(char *last)
{
	char	**args;
	char	*line;
	int		i;

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
		parsebuf->heredoc = read_args(parsebuf->str_in);
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

int	parse_token(t_lexer *lexerbuf, t_parsing *parsebuf)
{
	parsebuf->argv = parse_args(lexerbuf->tokenlist, lexerbuf, parsebuf);
	if (!parsebuf->argv)
	{
		parsebuf->next = NULL;
		return (0);
	}
	parsebuf->path = check_cmd(parsebuf->argv[0], lexerbuf->path);
	return (1);
}

//returns -1 if malloc error
int	parse(t_lexer *lexerbuf, t_parsing	*parsebuf)
{
	parsebuf->str_in = parse_redir_in(lexerbuf->tokenlist, &parsebuf->flag);
	parsebuf->str_out = parse_redir_out(lexerbuf->tokenlist, &parsebuf->flag);
	parsebuf->str_err = parse_redir_err(lexerbuf->tokenlist, &parsebuf->flag);
	if (lexerbuf->tokenlist->type == TOKEN)
	{
		if (!parse_token(lexerbuf, parsebuf))
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
			if (!parsebuf->next)
				return (-1);
			return (parse(lexerbuf, parsebuf->next));
		}
		lexerbuf->tokenlist = lexerbuf->tokenlist->next;
	}
	parsebuf->next = NULL;
	return (1);
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
	parserbuf->flag = 0;
	if (!parse(&lexerbuf, parserbuf))
		return (NULL);
	return (parserbuf);
}
