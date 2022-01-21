/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:23:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/21 17:17:44 by asaboure         ###   ########.fr       */
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
	t_lexer	lexerbuf;
	t_parsing	*parserbuf;

	line = readline(prompt);
	(void)ac;
	(void)av;
	lexerbuf.path = get_pathv(env);
	lexerbuf.tokenlist = malloc(sizeof(t_token));
	lexerbuf.j = 0;
	// while(path[i])
	// {
	// 	printf("%s\n", path[i]);
	// 	i++;
	// }

	lexer_build(line, ft_strlen(line), &lexerbuf);
	parserbuf = malloc(sizeof(t_parsing));
	parse(&lexerbuf, parserbuf);
	parserbuf->path = check_cmd(parserbuf->argv[0], lexerbuf.path);

	// while(lexerbuf.tokenlist)
	// {
 	// 	printf("%s (%d)\n", lexerbuf.tokenlist->data, lexerbuf.tokenlist->type);
	//  	lexerbuf.tokenlist = lexerbuf.tokenlist->next;
	// }

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
		printf("redir in: %s, (flag %d)\n", parserbuf->str_in, parserbuf->in);
		printf("redir out: %s (flag %d)\n", parserbuf->str_out, parserbuf->out);
		printf("redir err: %s (flag %d)\n", parserbuf->str_err, parserbuf->err);
		parserbuf = parserbuf->next;
		printf("\n");
	}
}