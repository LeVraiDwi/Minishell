#include "minishell.h"

/*char	*ft_get_str_pipe(int *pipefd)
{
	int		l;
	char	*str;
	char	*tmp;
	char	buff[500];

	l = 1;
	str = 0;
	while (l)
	{
		l = read(pipefd[0], buff, 500);
		if (l < 0)
			return (0);
		if (l > 0)
		{
			if (!str)
				str = ft_strdup(buff);
			else
			{
				tmp = str;
				str = ft_strjoin(str, buff);
				free(tmp);
			}
			if (!str)
				return (0);
		}
	}
	return (str);
}*/
