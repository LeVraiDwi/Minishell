#include "minishell.h"

int	ft_pwd(char **cmd)
{
	char	buf[200];
	
	if (!strisstr(cmd[0], "pwd"))
		return (1);
	getcwd(buf, 200);
	printf("%s\n", buf);
	return (0);
}
