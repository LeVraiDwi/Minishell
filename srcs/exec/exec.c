/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:19:33 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/04 15:48:13 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_pipe(t_parsing *cmd)
{
	if (cmd->in  > 1)
		close(cmd->in);
	if (cmd->out > 1)
		close(cmd->out);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}

void	ft_close(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

int	ft_child(t_term *term, t_parsing *cmd, int pipefd[2], int last_child)
{
	int	status;

	printf("%d\n", last_child);
	redir_flux(cmd, last_child);
	status = ft_exec_builtin(term, cmd);
	if (status <= 0)
		ft_free_pars(cmd);
	if (status < 0)
		exit(EXIT_FAILURE);
	else if (!status)
	{
		//free_term(term);
		ft_free_pars(cmd);
		exit(EXIT_SUCCESS);
	}
	ft_close(pipefd);
	printf("child: %d\n", last_child);
	execve(cmd->path, cmd->argv, term->env);
	perror("ERROR:\n");
	//free_term(term);
	ft_free_pars(cmd);
	exit(EXIT_FAILURE);
}

int	ft_exec_builtin(t_term *term, t_parsing *parsing)
{
	int	i;

	i = ft_is_builtin(parsing->argv[0]);
	if (i > 0)
		return (term->built[i](term, parsing->argv));
	return (1);
}

int	exec(t_term *term, t_parsing *cmd)
{
	int				child;
	int				status;
	int				last_child;
	int				nb_child;
	int				pipefd[2];

	last_child = 0;
	nb_child = 0;
	if (pipe(pipefd) < 0)
		return (-1);
	while (cmd)
	{
		if (!ft_setflux(cmd, pipefd))
		{
			if (cmd->path)
			{
				child = fork();
				if (child < 0)
					return (0);
				else if (child == 0)
					ft_child(term, cmd, pipefd, last_child);
				printf("fin_child: %d\n", child);
				last_child = child;
				status = 0;
				waitpid(-1, &status, 0);
				nb_child++;
			}
		}
		else
			perror(cmd->argv[0]);
		cmd = cmd->next;
	}
	close (pipefd[0]);
	close (pipefd[1]);
	while (nb_child--)
	{
	
	}	
	printf("fin\n");
	return (0);
}
