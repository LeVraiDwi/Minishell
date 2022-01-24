#include "minishell.h"

int	ft_cd(t_term *term, char **cmd)
{
	int	l;

	l = ft_cmd_length(cmd);
	if (l != 2)
	{
		strerror(E2BIG);
		return (1);
	}
	if(chdir(cmd[1]) < 0)
	{
		perror("Error:");
		return (1);
	}
	if(!ft_update_pwd(term))
		return (0);
	return (0);
}
