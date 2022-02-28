/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:39:19 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/27 23:35:30 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

int		ft_init_env(t_term *term, char **env);
int		ft_is_env_var(char *env, char *var);
int		ft_is_env(char **env, char *var);
int		ft_realloc_env(t_term *term, char *var);
int		add_env(t_term *term, char *var);
int		ft_free_env(char **env);
int		replace_env(t_term *term, char *var, int i);
int		ft_dealloc_env(t_term *term, int i);
int		remove_env(t_term *term, char *var);
void	print_env(t_term term, int std);
int		ft_update_pwd(t_term *term);
int		ft_set_pwd(t_term *term);
char	*get_env_var(char **env, char *var);
#endif
