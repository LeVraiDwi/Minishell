#include "minishell.h"

int	ft_add_history(char *str)
{
	if (!str & !*str)
		return (0);
	else
		add_history(str);
	return (0);
}
