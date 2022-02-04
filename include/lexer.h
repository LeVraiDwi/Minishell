/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:10:10 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/27 17:25:00 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

enum	e_tokenType
{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_QUOTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_WHITESPACE = ' ',
	CHAR_ESCAPESEQUENCE = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	TOKEN	= -1,
};

enum	e_inputState
{
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_ESCAPESEQ,
	STATE_GENERAL,
};

typedef struct s_token
{
	char			*data;
	int				type;
	struct s_token	*next;
}				t_token;

typedef struct s_lexer
{
	t_token	*tokenlist;
	char	**path;
	int		ntokens;
	int		state;
	int		i;
	int		j;
	int		chtype;
	char	c;
}				t_lexer;

int		set_token_quote(t_token *token, int *j);
int		set_token_dquote(t_token *token, int *j);
void	set_token_esc_seq(t_token *token, int *j, int *i, char *input);
void	set_token_general(t_token *token, int *j, char c);
t_token	*set_token_whitespace(t_token *token, int *j, int size, int i);

void	token_init(t_token *tok, int datasize);
int		getchartype(char c);

int		tokenize(t_lexer *lexerbuf, t_token *token, int size, char *input);
t_token	*tokenize_general(t_lexer *lexerbuf, t_token *token, char *input,
			int size);
void	tokenize_in_dquote(t_lexer *lexerbuf, t_token *token);
void	tokenize_in_quote(t_lexer *lexerbuf, t_token *token);
void	tokenize_null(t_lexer *lexerbuf, t_token *token);

int		lexer_build(char *input, int size, t_lexer *lexerbuf);
char	**get_pathv(char **env);

#endif
