/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:15:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 09:44:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	save_history(t_shell *shell, char *cmd)
{
	char	*tmp;

	add_history(cmd);
	if (shell->idx == 1)
	{
		tmp = ft_itoa(shell->idx);
		shell->history = ft_strdup(tmp);
		free(tmp);
		shell->history = ft_strjoin(shell->history, "  ");
		shell->history = ft_strjoin(shell->history, cmd);
		shell->history = ft_strjoin(shell->history, "\n");
	}
	else
	{
		tmp = ft_itoa(shell->idx);
		shell->history = ft_strjoin(shell->history, tmp);
		free(tmp);
		shell->history = ft_strjoin(shell->history, "  ");
		shell->history = ft_strjoin(shell->history, cmd);
		shell->history = ft_strjoin(shell->history, "\n");
	}
}