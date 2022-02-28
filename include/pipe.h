/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:31:47 by tcosse            #+#    #+#             */
/*   Updated: 2022/02/28 16:02:51 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

int		ft_creat_new_pipe(t_cmd **cmd);
int		ft_split_tab(t_cmd ***tab, t_cmd *cmd);
int		ft_free_cmd_tab(t_cmd **tab);
int		ft_split_pipe_cmd(t_cmd ***tab, t_cmd *cmd);
t_cmd	**ft_creat_tab(t_cmd *cmd);
t_cmd	**split_pipe(t_cmd *cmd);
t_cmd	*new_pipe(t_cmd *cmd);
#endif
