#include "minishell.h"

int	ft_free_term(t_term *term)
{
	ft_free_env(term->env);
	return (0);
}
