#include "minishell.h"

int	ft_get_new_cmd(char **tmp)
{
	int		status;
	int		child;
	int		pipefd[2];
	char	*str;

	status = 0;
	if (pipe(pipefd) < 0)
		return (0);
	child = fork();
	if (child < 0)
		return (ft_close(pipefd[0], pipefd[1]));
	else if (child == 0)
		ft_get_cmd(pipefd);
	close(pipefd[1]);
	status = 0;
	if (waitpid(0, &status, 0) < 0)
		return (ft_close(pipefd[0], pipefd[1]));
	str = ft_get_str_pipe(pipefd);
	ft_close(pipefd[0], pipefd[1]);
	if (!str)
		return (-1);
	*tmp = str;
	return (0);
}

int	ft_creat_new_pipe(t_cmd **cmd)
{
	char	*str;
	t_cmd	*new;
	
	if (ft_get_new_cmd(&str) < 0)
		return (-1);
	new = lexer(str);
	if (parser(new))
		return (ft_free_cmd(new));
	*cmd = new;
	return (0);
}

int	ft_is_valid_cmd(char *str)
{
	if (!str || !*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (str)
		return (1);
	return (0);
}

int	ft_get_cmd(int *pipefd)
{
	char 	*str;

	str = 0;
	while (!str)
	{
		str = readline("> ");
		if (!str)
		{
			ft_close(pipefd[0], pipefd[1]);
			exit(EXIT_FAILURE);
		}
		if (!ft_is_valid_cmd(str))
		{
			free(str);
			str = 0;
		}
	}
	write(pipefd[1], str, ft_strlen(str));
	ft_close(pipefd[0], pipefd[1]);
	free(str);
	exit(EXIT_SUCCESS);
	return (0);
}
