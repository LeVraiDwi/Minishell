/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:17:17 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/26 18:51:02 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_term		term;
	t_parsing	*parsebuf;
	char		*str;
	char		**cmd;
	int			i;
	//char	*cmd1[] = {"export", "a=12", "jaime=", "pain=jamenfkfhssflf", "0"};

	(void)argv;
	(void)argc;
	if(!init_term(&term, env))
		return (0);
	while (!term.exit)
	{
		str = readline("\033[34;01mMinishell\033[00m$ ");
		parsebuf = parse_init(str, env);
		cmd = ft_split(str, ' ');
		i = ft_is_builtin(*cmd);
		if (i < 0)
			term.exit = 1;
		else if (i >= 0)
			term.built[i](&term, cmd);
		free(str);
	}
	return (0);
}
