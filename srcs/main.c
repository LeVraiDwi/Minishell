/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:17:17 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 02:20:35 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int err = 0;

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

void	exit_minishell(t_term *term)
{
	printf("\n");
	ft_free_term(term);
	exit(0);
}

int	cmd(t_term *term)
{
	t_cmd	*cmd;
	t_cmd	**tab;
	char	*str;

	str = readline("\033[34;01mMinishell\033[00m$ ");
	if (str && *str && str[ft_skip_space(str, 0)])
	{
		ft_add_history(str);
		cmd = lexer(str);
		if (!cmd)
			return (free_err_cmd(0, 0, PERROR_ERR));
		if (parser(cmd))
			return (free_err_cmd(cmd, 0, PERROR_ERR));
		if (ft_check_pipe(cmd))
			return (free_err_cmd(cmd, 0, 0));
		if (ahdoc(term, cmd) < 0)
			return (free_err_cmd(cmd, 0, 0));
		tab = split_pipe(cmd);
		if (!tab)
			return (free_err_cmd(cmd, 0, PERROR_ERR));
		if (ft_check_parsing(tab) < 0)
			return (free_err_cmd(cmd, 0, 0));
		if (exec(term, tab) < 0)
			return (free_err_cmd(cmd, 0, 0));
		if (tab)
			ft_free_cmd_tab(tab);
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
	err = 0;
	signal_handler();
	if(init_term(&term, env))
		return (0);
	term.exit = 3;
	while (1)
	{
		cmd(&term);
	}
	ft_free_term(&term);
	rl_clear_history();
}
