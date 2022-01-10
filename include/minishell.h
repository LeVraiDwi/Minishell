/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:22:04 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/10 13:59:20 by tcosse           ###   ########.fr       */
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
# include <errno.h>
# define STDIN 0
# define STDOUT 1

typedef struct	s_parsing
{
	char				*path; //le path
	char				**argv; //tableau des argument 1er element le nom de la cmd eg: echo
	char				**env; //variable env du main
	unsigned int		flag;
	int					in;
	int					out;
	char				*str_in;
	char				*str_out;
	void				*next;
}				t_parsing;

#endif
