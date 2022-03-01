/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:26:53 by tcosse            #+#    #+#             */
/*   Updated: 2022/03/01 20:18:13 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H
# define SYNTAX_ERR 1
# define SYNTAX_STR "minishell: syntax error near unexpected token `"
# define SYNTAX_ERR_NEW_LINE "minishell: syntax error near unexpected token\
 `new line'\n"
# define CMD_NOT_FOUND "command not found"
# define PERROR_ERR 2
# define MINISHELL "minishell: "

int		ft_set_err(t_cmd *cmd, int err_num);
int		ft_set_syntax_err(t_cmd *cmd);
int		ft_error_std(t_cmd *cmd, int err);
int		ft_error_cmd(char *str);
int		ft_add_err(t_term *term, char *str);
int		free_err_cmd(t_cmd *cmd, t_cmd **tab, int perr);
int		ft_perror(void);
int		ft_set_ret_err(void);
int		set_status_err(int status, int success);
int		ft_ret_err(void);
char	*ft_creat_err_msg(char *arg, int err);
void	print_err(t_term *term);
#endif
