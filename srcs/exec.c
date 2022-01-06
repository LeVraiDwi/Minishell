#include "minishell.h"

void	ft_close_fd(int fd, int fd2)
{
	if (fd)
		close(fd);
	if (fd2)
		close(fd2);
}

int	ft_child(t_parsing cmd, t_term term, int nb_child)
{
	if (nb_child == 0)
	{
		if (cmd->in != 0)
			if(dub2(cmd->in, STDIN_FD))
				exit(EXIT_FAILURE);
	}
}

int	exec_tree(t_parsing cmd, t_term term)
{
	int				pipefd[2];
	unsigned int	nb_pid;
	int				child;
	int				status;

	status = 0;
	nb_child = 0;
	if (pipe(pipefd) < 0)
		return (0);
	while (cmd)
	{
		child = fork();
		if (child < 0)
			return (0);
		else if (child == 0)
			ft_child(cmd, pipefd, nb_child);
		nb_child++;
		cmd = cmd->next;
	}
	ft_close_fd(pipefd[0], pipefd[1]);
	while (nb_child--)
	{
		if (waitpid(-1, &status, 0) < 0)
			exit(EXIT_FAILURE);
	}
	ft_free_pars(cmd);
	exit(EXIT_SUCCESS);
}
