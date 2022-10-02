/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:15:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/02 14:15:59 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	save_history(t_history *history, char *cmd, int idx)
{
	char *tmp;

	if (idx == 1)
	{
		tmp = ft_itoa(idx);
		history->history = ft_strdup(tmp);
		free(tmp);
		history->history = ft_strjoin(history->history, "  ");
		history->history = ft_strjoin(history->history, cmd);
		history->history = ft_strjoin(history->history, "\n");
	}
	else
	{
		tmp = ft_itoa(idx);
		history->history = ft_strjoin(history->history, tmp);
		free(tmp);
		history->history = ft_strjoin(history->history, "  ");
		history->history = ft_strjoin(history->history, cmd);
		history->history = ft_strjoin(history->history, "\n");
	}
}
