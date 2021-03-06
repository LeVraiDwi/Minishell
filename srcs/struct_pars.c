/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:19:17 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/04 16:27:27 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_init_struct(t_parsing *pars)
{
	pars->path = 0;
	pars->argv = 0;
	pars->flag = 0;
	pars->next = 0;
	pars->cmd = 0;
	pars->quote_in = 0;
	pars->quote_out = 0;
	pars->quote_err = 0;
	pars->in = STDIN;
	pars->out = STDOUT;
	pars->str_in = 0;
	pars->str_out = 0;
}

t_parsing	*ft_creat_pars(void)
{
	t_parsing	*new;

	new = (t_parsing *)malloc(sizeof(t_parsing) * 1);
	if (!new)
		return (0);
	ft_init_struct(new);
	return (new);
}

int	ft_free(void **p)
{
	if (*p)
	{
		free(*p);
		*p = 0;
	}
	return (0);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv && *argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

int	ft_free_pars(t_parsing *pars)
{
	if (pars->next)
		ft_free_pars(pars->next);
	if (pars->path)
		ft_free((void **)&pars->path);
	if (pars->argv)
		ft_free_argv(pars->argv);
	if (pars->str_in)
		ft_free((void **)&pars->str_in);
	if (pars->str_out)
		ft_free((void **)&pars->str_out);
	ft_free((void **)&pars);
	return (0);
}
