/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:12 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/23 16:18:29 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_env(t_term *term, char **env)
{
	int		l;
	char	**new;

	l = 0;
	while (env[l])
		l++;
	new = (char **)malloc(sizeof(char *) * (l + 1));
	if (!new)
		return (0);
	new[l] = 0;
	l = 0;
	while (env[l])
	{
		new[l] = ft_strdup(env[l]);
		if (!new[l])
			return (0);
		l++;
	}
	term->env = new;
	return (1);
}

int	ft_is_env_var(char *env, char *var)
{
	int	i;

	i = 0;
	while (env[i] && var[i] && env[i] != '=')
	{
		if (env[i] != var[i])
			return (0);
		i++;
	}
	if (env[i] == '=' && (var[i] == '=' || !var[i]))
		return (1);
	return (0);
}

int	ft_is_env(char **env, char *var)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_is_env_var(env[i], var))
			return (i);
		i++;
	}
	return (0);
}

int	ft_realloc_env(t_term *term, char *var)
{
	int		l;
	char	**tmp;

	l = 0;
	while (term->env[l])
		l++;
	tmp = (char **)malloc(sizeof(char *) * (l + 2));
	if (!tmp)
		return (0);
	tmp[l + 1] = 0;
	l = 0;
	while (term->env[l])
	{
		tmp[l] = term->env[l];
		l++;
	}
	tmp[l] = ft_strdup(var);
	if (!tmp[l])
		return (ft_free_env(tmp));
	free(term->env);
	term->env = tmp;
	return (1);
}

int	add_env(t_term *term, char *var)
{
	int	i;

	if (!var)
		return (1);
	i = ft_is_env(term->env, var);
	if (i)
	{
		replace_env(term, var, i);
		return (1);
	}
	else
		if (!ft_realloc_env(term, var))
			return (0);
	return (1);
}
