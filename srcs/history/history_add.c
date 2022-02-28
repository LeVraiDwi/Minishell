/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:50:10 by asaboure          #+#    #+#             */
/*   Updated: 2022/02/28 17:50:12 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_history(char *str)
{
	if (!str & !*str)
		return (0);
	else
		add_history(str);
	return (0);
}
