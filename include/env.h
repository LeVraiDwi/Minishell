/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:39:19 by tcosse            #+#    #+#             */
/*   Updated: 2022/01/24 15:44:09 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_term	t_term;

int		ft_init_env(t_term *term, char **env);
int		ft_is_env_var(char *env, char *var);
int		ft_is_env(char **env, char *var);
int		ft_realloc_env(t_term *term, char *var);
int		add_env(t_term *term, char *var);
int		ft_free_env(char **env);
int		replace_env(t_term *term, char *var, int i);
int		ft_dealloc_env(t_term *term, int i);
int		remove_env(t_term *term, char *var);
void		print_env(t_term term, int std);
int		ft_update_pwd(t_term *term);
char		*get_env_var(char **env, char *var);
#endif
