/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:37:38 by asaboure          #+#    #+#             */
/*   Updated: 2022/03/01 18:40:16 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

void	signal_handler_heredoc(int id);
void	signal_set_err(int sig, siginfo_t *info, void *context);
void	signal_handler_child(int id);
void	signal_handler(void);
#endif
