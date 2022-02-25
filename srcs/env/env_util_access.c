/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:20:01 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/17 14:04:12 by tcosse           ###   ########.fr       */
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
	if (i)
		return (get_val(env[i]));
	else
		return (ft_strdup(""));
	return (0);
}

int	ft_update_pwd(t_term *term)
{
	char	*tmp;
	char	*var;
	char	buf[500];

	var = get_env_var(term->env, "PWD");
	if (!var)
		return (0);
	tmp = ft_strjoin("OLDPWD=", var);
	free(var);
	add_env(term, tmp);
	free(tmp);
	getcwd(buf, 500);
	tmp = ft_strjoin("PWD=", buf);
	add_env(term, tmp);
	free(tmp);
	return (1);
}
