/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:32:24 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 01:21:59 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

int	ft_check_redir(t_cmd *cmd);
int	ft_is_cmd(t_cmd *cmd);
int	ft_set_cmd(t_cmd *cmd);
int	ft_check_flag(t_cmd *cmd);
int	check_file(t_cmd *cmd);
int	ft_isdir(char *path);
int	ft_check_parsing(t_cmd **tab);
int	ft_check_pipe(t_cmd *cmd);
#endif
