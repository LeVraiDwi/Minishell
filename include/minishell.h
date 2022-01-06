/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:22:04 by asaboure          #+#    #+#             */
/*   Updated: 2022/01/06 18:22:06 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>


typedef struct	s_parsing
{
	char				**path; //le path
	char				**argv; //tableau des argument 1er element le nom de la cmd eg: echo
	char				**env; //variable env du main
	unsigned int		flag;
	void				*next;
}				t_parsing;

#endif
