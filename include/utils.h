/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:10:10 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 18:43:04 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_isspace(char c);
int		ft_isquote(char c);
int		ft_quotelen(char *str, int start, char c);
int		ft_close(int fd1, int fd2);
char	*ft_insertvar(char *s, char *str, int var_start, int var_L);
void	newprompt(int sig);
int		isnumber(char *str);
#endif
