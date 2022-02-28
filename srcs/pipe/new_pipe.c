#include "minishell.h"

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
