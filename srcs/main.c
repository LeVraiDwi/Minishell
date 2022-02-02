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
	t_parsing	*tmp;
	//char	*cmd1[] = {"export", "a=12", "jaime=", "pain=jamenfkfhssflf", "0"};

	(void)argv;
	(void)argc;
	if(init_term(&term, env))
		return (0);
	while (!term.exit)
	{
		i = 0;
		str = readline("\033[34;01mMinishell\033[00m$ ");
		cmd = ft_split(str, ' ');
		parsebuf = parse_init(str, env);
		printf("okay:%p, %p\n", parsebuf, parsebuf->argv);
		i = 0;
		while (parsebuf->argv && parsebuf->argv[i])
		{
			printf("cmd:%s\n", parsebuf->argv[i]);
			i++;
		}
		i = 0;
		while (parsebuf->argv && parsebuf->argv[i])
		{
			printf("cmd:%s\n", parsebuf->argv[i]);
			i++;
		}
		printf("%s\n", parsebuf->str_in);
		printf("%s\n", parsebuf->str_out);
		printf("%s\n", parsebuf->str_err);
		printf("%d\n", parsebuf->flag);
		printf("in: %d\n", parsebuf->in);
		printf("out: %d\n", parsebuf->out);
		printf("err: %d\n", parsebuf->err);
		printf("======================debut expanser==================\n");
		expanser(&term, parsebuf);
		printf("okay:%p, %p\n", parsebuf, parsebuf->argv);
		tmp = parsebuf;
		while (parsebuf)
		{
			i = 0;
			while (parsebuf->argv && parsebuf->argv[i])
			{
				printf("cmd:%s\n", parsebuf->argv[i]);
				i++;
			}
			i = 0;
			while (parsebuf->argv && parsebuf->argv[i])
			{
				printf("cmd:%s\n", parsebuf->argv[i]);
				i++;
			}
			printf("%s\n", parsebuf->str_in);
			printf("%s\n", parsebuf->str_out);
			printf("%s\n", parsebuf->str_err);
			printf("%d\n", parsebuf->flag);
			printf("in: %d\n", parsebuf->in);
			printf("out: %d\n", parsebuf->out);
			printf("err: %d\n", parsebuf->err);
			if (parsebuf->out)
				write(parsebuf->out, "ha", 2);
			if (parsebuf->out)
				close(parsebuf->out);
			parsebuf = parsebuf->next;
		}
		ft_free_pars(tmp);
		/*	i = ft_is_builtin(*cmd);
		if (i < 0)
			term.exit = 1;
		else if (i >= 0)
			term.built[i](&term, cmd);*/
		free(str);
	}
	return (0);
}
