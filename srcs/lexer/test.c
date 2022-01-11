/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:23:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/11 18:45:51 by asaboure         ###   ########.fr       */
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
	int		i;
	char	**path;
	t_lexer	lexerbuf;
	char	*input = "plouf";
	//line = readline(prompt);
	i = 0;

	lexerbuf.path = get_pathv(env);
	// while(path[i])
	// {
	// 	printf("%s\n", path[i]);
	// 	i++;
	// }

	lexer_build(input, ft_strlen(input), &lexerbuf);
}