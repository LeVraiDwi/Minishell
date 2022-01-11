#include "minishell.h"

int	strisstr(char str, char s)
{
	int i;

	i = 0;
	if (!str || !s)
		return (0);
	while (str[i] && s[i] && str[i] == s[i])
		i++;
	if (str[i] || str[i])
		return (0);
	return (1);
}
