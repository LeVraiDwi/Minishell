#include "minishell.h"

int	ft_free_term(t_term **term)
{
	int	i;

	i = 0;
	while ((*term)->env[i])
	{
		free((*term)->env[i]);
		(*term)->env[i] = 0;
		i++;
	}
	if ((*term)->env)
		free((*term)->env);
	return (0);
}
