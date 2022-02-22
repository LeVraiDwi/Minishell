/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:23:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "lexer.h"
#include "parser.h"

// clang -Wall -Werror -Wextra -I../../libft/ -I ../../include -lreadline -L../../libft -lft test.c lexer.c lexer_utils.c set_token.c tokenize.c ../parser/parser.c ../../libft/libft.a
int	main(int ac, char **av, char **env)
{
	char	*prompt = "minishell> ";
	char	*line;
	int		i = 0;
	t_parsing	*parserbuf;

	line = readline(prompt);
	(void)ac;
	(void)av;
	parserbuf = parse_init(line, env);
	while (parserbuf)
	{
		printf("args: ");
		i = 0;
		while (parserbuf->argv[i])
		{
			printf("%s, ", parserbuf->argv[i]);
			i++;
		}
		printf("\n");
		i = 0;
		if (parserbuf->flag & DOUBLE_STDIN)
		{
			printf("heredoc: ");
			while (parserbuf->heredoc[i])
			{
				printf("%s, ", parserbuf->heredoc[i]);
				i++;
			}
		}
		printf("\n");
		printf("path: %s\n", parserbuf->path);
		printf("redir in: %s, (flag %d)\n", parserbuf->str_in, parserbuf->flag);
		printf("redir out: %s (flag %d)\n", parserbuf->str_out, parserbuf->flag);
		printf("redir err: %s (flag %d)\n", parserbuf->str_err, parserbuf->flag);
		parserbuf = parserbuf->next;
		printf("\n");
	}
}