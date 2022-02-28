/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:15:35 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 20:39:53 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_flux(t_parsing *cmd, int last_child)
{
	int	status;

	status = 0;
	if (last_child != 0)
		waitpid(last_child, &status, 0);
	if (cmd->in != STDIN)
		if (dup2(cmd->in, STDIN) < 0)
			return (ft_error_pipe(cmd));
	if (cmd->out != STDOUT)
		if (dup2(cmd->out, STDOUT) < 0)
			return (ft_error_pipe(cmd));
	return (0);
}

int	ft_is_exit(t_term *term, t_parsing *exec, t_cmd **tab, int i)
{
	if (i != 0 || tab[i + 1])
		return (0);
	if (strisstr(exec->argv[0], "exit"))
	{	
		term->exit(term, exec, tab);
	}
	return (0);
}
