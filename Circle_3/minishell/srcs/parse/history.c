/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:15:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/03 10:39:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	save_history(t_shell *shell, char *cmd, int idx)
{
	char	*tmp;

	add_history (cmd);
	if (idx == 1)
	{
		tmp = ft_itoa(idx);
		shell->history = ft_strdup(tmp);
		free(tmp);
		shell->history = ft_strjoin(shell->history, "  ");
		shell->history = ft_strjoin(shell->history, cmd);
		shell->history = ft_strjoin(shell->history, "\n");
	}
	else
	{
		tmp = ft_itoa(idx);
		shell->history = ft_strjoin(shell->history, tmp);
		free(tmp);
		shell->history = ft_strjoin(shell->history, "  ");
		shell->history = ft_strjoin(shell->history, cmd);
		shell->history = ft_strjoin(shell->history, "\n");
	}
}
