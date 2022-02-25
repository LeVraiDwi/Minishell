#include "minishell.h"

int	ft_free_term(t_term *term)
{
	ft_free_env(term->env);
	ft_free_term_err(term);
	return (0);
}

void	ft_free_term_err(t_term *term)
{
	int	i;

	i = 0;
	while (term->err && term->err[i])
		free(term->err[i++]);
	if (term->err)
		free(term->err);
	term->is_err = 0;
	term->err = 0;
}
