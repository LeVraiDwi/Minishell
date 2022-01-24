/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:19:17 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:43:23 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_init_struct(t_parsing *pars)
{
	pars->path = 0;
	pars->argv = 0;
	pars->env = 0;
	pars->flag = 0;
	pars->next = 0;
	pars->in = 0;
	pars->out = 0;
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

void	ft_free(void **p)
{
	if (*p)
	{
		free(*p);
		*p = 0;
	}
}

void	ft_free_argv(char ***argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			ft_free(&argv[i++]);
		ft_free(&argv);
	}
}

int	ft_free_pars(t_parsing *pars)
{
	if (pars->next)
		ft_rm_pars(pars->next);
	if (pars->path)
		ft_free(&pars->path);
	ft_free_argv(pars->argv);
	if (pars->str_in)
		ft_free(&pars->str_in);
	if (pars->str_out)
		ft_free(&pars->str_out);
	ft_free(&pars);
	exit(EXIT_FAILURE);
}
