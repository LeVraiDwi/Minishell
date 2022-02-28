/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:01 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 01:02:06 by asaboure         ###   ########.fr       */
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
	if (ft_is_env(term->env, "PWD") >= 0)
		return (ft_set_pwd(term));
	return (1);
}

int	ft_set_pwd(t_term *term)
{
	char	*tmp;
	char	buf[1000];

	getcwd(buf, 1000);
	tmp = ft_strjoin("PWD=", buf);
	add_env(term, tmp);
	free(tmp);
	return (1);
}