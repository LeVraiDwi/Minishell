/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:22:04 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/10 14:36:51 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "built.h"
# include "env.h"
# include "strisstr.h"
# define STDIN 0
# define STDOUT 1

typedef struct	s_term
{
	char	*user;
	char	**env;
}		t_term;

typedef struct	s_parsing
{
	char				*path; //le path
	char				**argv; //tableau des argument 1er element le nom de la cmd eg: echo
	char				**env; //variable env du main
	unsigned int		flag;
	int					in;
	int					out;
	int					err;
	char				*str_in;
	char				*str_out;
	char				*str_err;
	void				*next;
}				t_parsing;

int	strisstr(char *str, char *s);
int	ft_free(void **p);

#endif
