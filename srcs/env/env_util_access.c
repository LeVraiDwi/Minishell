/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:01 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 14:59:16 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_val(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	return (ft_strdup(env + i));
}

char	*get_env_var(char **env, char *var)
{
	int	i;

	i = ft_is_env(env, var);
	if (i >= 0)
		return (get_val(env[i]));
	else
		return (ft_strdup(""));
	return (0);
}

int	ft_update_pwd(t_term *term)
{
	char	*tmp;
	char	*var;

	var = get_env_var(term->env, "PWD");
	if (!var)
		return (0);
	tmp = ft_strjoin("OLDPWD=", var);
	free(var);
	add_env(term, tmp);
	free(tmp);
	getcwd(term->cwd, 1000);
	if (ft_is_env(term->env, "PWD") >= 0)
	{
		tmp = ft_strjoin("PWD=", term->cwd);
		add_env(term, tmp);
		free(tmp);
	}
	return (1);
}

int	ft_set_pwd(t_term *term)
{
	char	*tmp;

	getcwd(term->cwd, 1000);
	tmp = ft_strjoin("PWD=", term->cwd);
	add_env(term, tmp);
	free(tmp);
	return (1);
}
