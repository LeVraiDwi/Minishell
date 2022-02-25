/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:32:35 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/25 18:32:36 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSER_H
# define EXPANSER_H
# define HOME_STR "HOME"

int		ft_insert_var(t_cmd *cmd, char **env);
int		replace_var(t_term *term, t_parsing *parsing);
int		expanser(t_term *term, t_cmd **tab);
int		ft_setstd(t_parsing *parsing);
int		ft_creat_argv(t_parsing *parsing);
int		count_argv(t_parsing *parsing);
int		ft_creat_all_arg(t_parsing *parsing);
int		ft_creat_std(char **std, t_cmd *cmd);
int		make_quote(t_parsing *parsing);
int		ft_join_arg(t_cmd *tmp, char **new, int *l);
int		ft_do_quote(t_cmd **cmd, int i, int *l);
int		ft_set_new_cmd(t_cmd *cmd, char *tmp, int start, int l);
int		ft_is_home(char *cmd, int l, int flag);
int		ft_replace_cmd(t_term *term, t_cmd *cmd);
#endif
