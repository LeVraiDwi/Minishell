/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:23:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/12 17:29:49 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "lexer.h"

int	main(int ac, char **av, char **env)
{
	//char	*prompt = "minishell> ";
	//char	*line;
	// int		i;
	t_lexer	lexerbuf;
	char	*input = "plouf d";
	//line = readline(prompt);
	// i = 0;
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

	lexer_build(input, ft_strlen(input), &lexerbuf);
	while(lexerbuf.tokenlist)
	{
 		printf("%s\n", lexerbuf.tokenlist->data);
	 	lexerbuf.tokenlist = lexerbuf.tokenlist->next;
	}
}