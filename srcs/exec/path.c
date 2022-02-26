/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:20:20 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/26 19:21:43 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			i = -1;
			while (path[++i])
				path[i] = ft_strjoin(path[i], "/");
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*check_cmd(char *input, char **path)
{
	int		i;
	char	*pathcmd;

	i = 0;
	if (access(input, X_OK | F_OK) == 0)
		return (ft_strdup(input));
	while (path[i])
	{
		pathcmd = ft_strjoin(path[i], input);
		if (!pathcmd)
			return (NULL);
		if (access(pathcmd, X_OK | F_OK) == 0)
			return (ft_strdup(pathcmd));
		free(pathcmd);
		i++;
	}
	return (NULL);
}

int	ft_get_path(t_term *term, t_parsing *exec)
{
	char	**pathv;

	pathv = get_pathv(term->env);
	if (!pathv)
		return (-1);
	exec->path = check_cmd(exec->argv[0], pathv);
	ft_free_env(pathv);
	if (!exec->path)
		return (-1);
	return (0);
}

void	ft_dup_pipe(int *old, int *new)
{
	new[0] = old[0];
	new[1] = old[1];
}

void	ft_select_std(t_parsing *exec, t_cmd *next)
{
	if (next)
	{
		if (exec->out == STD_OUT)
			exec->out = exec->pipe_out[1];
	}
	else if (!exec->out)
			exec->out = STD_OUT;
	if (exec->pipe_in[1] > 1 && exec->pipe_in[0] > 1)
	{
		if (exec->in == STD_IN)
			exec->in = exec->pipe_in[0];
	}
}
