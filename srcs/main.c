/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:17:17 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 22:21:45 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_err = 0;

void	newprompt(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	exit_minishell(t_term *term)
{
	printf("exit\n");
	ft_free_term(term);
	exit(0);
}

int	ft_exec_cmd(t_term *term, char *str)
{
	ft_add_history(str);
	term->act_cmd = lexer(str);
	if (!term->act_cmd)
		return (free_err_cmd(0, 0, PERROR_ERR));
	if (parser(term->act_cmd))
		return (free_err_cmd(term->act_cmd, 0, PERROR_ERR));
	if (ft_check_pipe(term->act_cmd))
		return (free_err_cmd(term->act_cmd, 0, 0));
	if (ahdoc(term, term->act_cmd) < 0)
		return (free_err_cmd(term->act_cmd, 0, 0));
	term->act_tab = split_pipe(term->act_cmd);
	if (!term->act_tab)
		return (free_err_cmd(term->act_cmd, 0, PERROR_ERR));
	if (ft_check_parsing(term->act_tab) < 0)
		return (free_err_cmd(term->act_cmd, 0, 0));
	if (expanser(term, term->act_tab) < 0)
		return (free_err_cmd(term->act_cmd, 0, 0));
	if (exec(term, term->act_tab) < 0)
		return (free_err_cmd(term->act_cmd, 0, 0));
	if (term->act_tab)
		ft_free_cmd_tab(term->act_tab);
	return (0);
}

int	cmd(t_term *term)
{
	char	*str;

	str = readline("\033[34;01mMinishell\033[00m$ ");
	if (str && *str && str[ft_skip_space(str, 0)])
	{
		if (ft_exec_cmd(term, str) < 0)
			return (-1);
	}
	else if (!str)
		exit_minishell(term);
	else
		free(str);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_term		term;

	(void)argv;
	(void)argc;
	g_err = 0;
	if (!isatty(0))
	{
		printf("forbidden input\n");
		return (0);
	}
	signal_handler();
	if (init_term(&term, env))
		return (0);
	while (1)
	{
		term.act_cmd = 0;
		term.act_tab = 0;
		term.act_pars = 0;
		cmd(&term);
	}
	ft_free_term(&term);
	rl_clear_history();
	write(1, "\n", 1);
}
