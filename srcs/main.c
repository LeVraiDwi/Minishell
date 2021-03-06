/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:17:17 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/26 19:11:42 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	newprompt()
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler()
{
	signal(SIGINT, newprompt);
	signal(SIGQUIT, SIG_IGN);
}

void	destroy_parsebuf(t_parsing *parsebuf)
{
	t_parsing *next;
	
	if (!parsebuf)
		return ;
	free(parsebuf->path);
	while (parsebuf)
	{
		next = parsebuf->next;
		free(parsebuf);
		parsebuf = next;
	}
}

int	exit_minishell(t_parsing *parsebuf)
{
	destroy_parsebuf(parsebuf);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_term		term;
	t_parsing	*parsebuf;
	char		*str;
	int			i;
	t_parsing	*tmp;
	//char	*cmd1[] = {"export", "a=12", "jaime=", "pain=jamenfkfhssflf", "0"};

	(void)argv;
	(void)argc;
	signal_handler();
	if(init_term(&term, env))
		return (0);
	while (!term.exit)
	{
		i = 0;
		str = readline("\033[34;01mMinishell\033[00m$ ");
		if (!str)
		{
			printf("exit\n");
			return (exit_minishell(parsebuf));
		}
		ft_add_history(str);
		printf("======================debut parsing==================\n");
		parsebuf = parse_init(str, env);
		if (!parsebuf)
			continue ;
		printf("okay:%p, %p, next:%p\n", parsebuf, parsebuf->argv, parsebuf->next);
		tmp = parsebuf;
		while (parsebuf)
		{
			i = 0;
			while (parsebuf->argv && parsebuf->argv[i])
			{
				printf("cmd:%s\n", parsebuf->argv[i]);
				i++;
			}
			printf("%s\n", parsebuf->str_in);
			printf("%s\n", parsebuf->str_out);
			printf("%s\n", parsebuf->str_err);
			printf("%s\n", parsebuf->path);
			printf("%d\n", parsebuf->flag);
			printf("in: %d\n", parsebuf->in);
			printf("out: %d\n", parsebuf->out);
			printf("err: %d\n", parsebuf->err);
			parsebuf = parsebuf->next;
		}
		parsebuf = tmp;
		printf("======================fin parsing==================\n");
		printf("======================debut expanser==================\n");
		printf("okay:%p, %p, next:%p\n", parsebuf, parsebuf->argv, parsebuf->next);
		expanser(&term, parsebuf);
		tmp = parsebuf;
		while (parsebuf)
		{
			printf("parsebuf next: %p, %p\n", parsebuf->argv, parsebuf->argv[0]);
			i = 0;
			while (parsebuf->argv && parsebuf->argv[i])
			{
				printf("cmd:%s\n", parsebuf->argv[i]);
				i++;
			}
			printf("%s\n", parsebuf->str_in);
			printf("%s\n", parsebuf->str_out);
			printf("%s\n", parsebuf->str_err);
			printf("%s\n", parsebuf->path);
			printf("%d\n", parsebuf->flag);
			printf("in: %d\n", parsebuf->in);
			printf("out: %d\n", parsebuf->out);
			printf("err: %d\n", parsebuf->err);
			parsebuf = parsebuf->next;
		}
		printf("======================fin expanser==================\n");
		printf("======================debut exec==================\n");
		exec(&term, tmp);
		printf("======================fin exec==================\n");
		if (strisstr("EXIT", tmp->argv[0]))
			term.exit = 1;
		ft_free_pars(tmp);
		free(str);
		destroy_parsebuf(parsebuf);
	}
	ft_free_term(&term);
	return (0);
}
