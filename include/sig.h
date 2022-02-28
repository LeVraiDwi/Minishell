/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:37:38 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 18:37:39 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

void	signal_handler_heredoc(int id);
void	sigint_set_err(int sig);
void	signal_handler_child(int id);
void	signal_handler(void);
#endif
