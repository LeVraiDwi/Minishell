#include "minishell.h"

int	ft_error_pipe(t_parsing cmd)
{
	if (cmd->in > 2)
		close(cmd->in);
	if (cmd->out > 2)
		close(cmd->out);
	free_struct(cmd)
	exit(EXIT_FAILURE);
}

int	ft_child(t_parsing cmd, int nb_child, int	last_child)
{
	int	status;

	status = 0;
	if(last_child != 0)
		waitpid(last_child, &status, 0);
	if (dub2(cmd->in, STDIN) < 0)
		exit(ft_error_pipe(cmd));
	if (dub2(cmd->out, STDOUT) < 0)
		exit(ft_error_pipe(cmd));
	execve(cmd->path, cmd->argv, cmd->env);
	perror("ERROR:");
	ft_free_struct(cmd);
	exit(EXIT_FAILURE);
}

int	exec(t_parsing cmd)
{
	unsigned int	nb_pid;
	int				child;
	int				status;
	int				last_child;

	status = 0;
	nb_child = 0;
	last_child = 0;
	while (cmd)
	{
		child = fork();
		if (child < 0)
			return (0);
		else if (child == 0)
			ft_child(cmd, pipefd, nb_child, last_child);
		nb_child++;
		cmd = cmd->next;
		last_child = child;
	}
	ft_close_fd(pipefd[0], pipefd[1]);
	while (nb_child--)
	{
		if (waitpid(-1, &status, 0) < 0)
			exit(EXIT_FAILURE);
	}
	ft_free_struct(cmd);
	exit(EXIT_SUCCESS);
}
