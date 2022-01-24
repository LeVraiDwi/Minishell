/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:20 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 13:33:44 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_term *term, char **cmd)
{
	char	buf[200];

	(void)term;
	if (!strisstr(cmd[0], "pwd"))
		return (1);
	getcwd(buf, 200);
	printf("%s\n", buf);
	return (0);
}
