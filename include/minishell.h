/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:22:04 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/26 18:07:04 by asaboure         ###   ########.fr       */
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
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "struct.h"
# include "libft.h"
# include "built.h"
# include "env.h"
# include "strisstr.h"
# include "lexer.h"
# include "parser.h"
# include "expanser.h"
# include "exec.h"
# include "history.h"
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define DOUBLE_STDIN 1
# define DOUBLE_STDOUT 2
# define SIMPLE_STDIN 4
# define SIMPLE_STDOUT 8
# define SIMPLE_STDERR 16
# define DOUBLE_STDERR 32
# define APPEND 2

int		strisstr(char *str, char *s);
int		ft_free(void **p);
int		init_term(t_term *term, char **env);
void	init_built(t_term *term);
void	ft_set_null(char **str, int l);
void	signal_handler();
#endif
