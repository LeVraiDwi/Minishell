/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:39:34 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 16:27:28 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H
# define FLAG_N 1
# define CD 0
# define EXPORT 1
# define UNSET 2
# define PWD 3
# define ENV 4
# define ECHO 5
# define EXIT 6

typedef struct s_term	t_term;

int		is_flag(char *arg);
void	ft_echo_new_line(int flag);
int		ft_is_var(char *var);
int		ft_is_valid_name(char *cmd);
int		ft_cmd_length(char **cmd);
int		ft_env(t_term *term, t_parsing *parsing);
int		ft_export(t_term *term, t_parsing *parsing);
int		ft_unset(t_term *term, t_parsing *parsing);
int		ft_pwd(t_term *term, t_parsing *paring);
int		ft_echo(t_term *term, t_parsing *parsing);
int		ft_cd(t_term *term, t_parsing *parsing);
int		ft_is_builtin(char *cmd);
int		return_new_line(void);
int		ft_exit(t_term *term, t_parsing *parsing, t_cmd **tab, t_parsing *pars);
#endif
