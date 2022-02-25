#include "minishell.h"

void	print_err(t_term *term)
{
	int	i;

	if (!term->is_err || !term->err)
		return;
	i = 0;
	while (term->err[i])
	{
		write(2, "minishell: ", 11);
		write(2, term->err[i], ft_strlen(term->err[i]));
		write(2, "\n", 1);
		i++;
	}
	ft_free_term_err(term);
	return;
}
