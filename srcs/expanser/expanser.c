/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:28:34 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/23 16:55:27 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	replace_var(t_term *term, t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!parsing)
		return (0);
	if (ft_replace_cmd(term, parsing->cmd) < 0)
		return (-1);
	if (ft_replace_cmd(term, parsing->quote_in) < 0)
		return (-1);
	if (ft_replace_cmd(term, parsing->quote_out) < 0)
		return (-1);
	if (ft_replace_cmd(term, parsing->quote_err) < 0)
		return (-1);
	return (0);
}

int	ft_stdopen(char *path, int *fd, int flags, int right)
{
	*fd = ft_openfile(path, flags, right);
	if (*fd < 0)
		return (-1);
	return (0);
}*/

int	expanser(t_term *term, t_cmd **tab)
{
	int	i;
	t_cmd	*tmp;

	i = 0;
	while (tab[i])
	{
		tmp = tab[i];
		if (ft_replace_cmd(term, tmp) < 0)
			return (-1);
		i++;
	}
	return (0);
}
