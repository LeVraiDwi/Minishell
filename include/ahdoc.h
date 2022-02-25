/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahdoc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:33:06 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/25 18:33:10 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AHDOC_H
# define AHDOC_H

int		ft_make_var(t_term *term, t_cmd *tab);
int		ft_replace_in_tab(t_term *term, t_cmd *tab);
int		ft_ahdoc_var_len(char *str);
int		ft_free_ahdoc(t_term *term, t_cmd *cmd, char *str, int exit_state);
int		ft_make_replace(t_term *term, t_cmd *tab, int *i);
int		ft_write_tab(t_term *term, t_cmd *cmd, t_cmd *tab);
int		ft_ahdoc(t_term *term, t_cmd *cmd, char *limiter);
int		ft_creat_ahdoc(t_term *term, t_cmd *cmd, char *limiter);
int		ahdoc(t_term *term, t_cmd *cmd);
char	*ft_is_ahdoc(t_cmd *cmd);
#endif
