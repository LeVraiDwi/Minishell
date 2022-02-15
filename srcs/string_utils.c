#include "minishell.h"

void	ft_set_null(char **str, int l)
{
	while (l--)
		*str++ = 0;
}
