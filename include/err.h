/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:26:53 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/25 18:36:06 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H
# define SYNTAX_ERR 1
# define SYNTAX_STR "minishell: syntax error near unexpected token `"
# define SYNTAX_ERR_NEW_LINE "minishell: syntax error near unexpected token `new line'\n"

int		ft_set_err(t_cmd *cmd, t_cmd *first, int err_num);
int		ft_set_syntax_err(t_cmd *cmd);
int		ft_error_std(t_term *term, t_cmd *cmd, int err);
int		ft_add_err(t_term *term, char *str);
char	*ft_creat_err_msg(char *arg, int err);
void	print_err(t_term *term);
#endif
