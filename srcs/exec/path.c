/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:20 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 23:43:46 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_slash(char **path)
{
	char	*tmp;
	int		i;

	i = -1;
	while (path[++i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(tmp);
		if (!path[i])
		{
			ft_free_env(path);
			return (-1);
		}
	}
	return (0);
}

char	**get_pathv(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + ft_strlen("PATH="), ':');
			if (add_slash(path) < 0)
				return (0);
			return (path);
		}
		i++;
	}
	return (NULL);
}

int	is_path(char *input)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (input[i])
	{
		if (input[i] == '/')
			ret = 1;
		i++;
	}
	return (ret);
}

char	*check_cmd(char *input, char **path)
{
	int		i;
	char	*pathcmd;

	i = 0;
	if (input[0] == '\0')
		return (NULL);
	if (is_path(input))
	{
		if (access(input, X_OK | F_OK) == 0)
			return (ft_strdup(input));
		return (NULL);
	}
	while (path[i])
	{
		pathcmd = ft_strjoin(path[i], input);
		if (!pathcmd)
			return (NULL);
		if (access(pathcmd, X_OK | F_OK) == 0)
			return (pathcmd);
		free(pathcmd);
		i++;
	}
	return (NULL);
}

int	ft_get_path(t_term *term, t_parsing *exec)
{
	char	**pathv;

	if (!exec->argv)
		return (-1);
	if (ft_is_builtin(exec->argv[0]) >= 0)
		return (0);
	pathv = get_pathv(term->env);
	if (!pathv)
		return (-1);
	exec->path = check_cmd(exec->argv[0], pathv);
	ft_free_env(pathv);
	if (!exec->path)
		return (-1);
	return (0);
}
