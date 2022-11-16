/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:53:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 09:43:59 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	find_path(t_shell *shell, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			if (!path)
				error_exit("Error : Environment", 1);
			shell->path = ft_split(path, ':');
			if (!shell->path)
				error_exit("Error : Environment", 1);
			return ;
		}
		i++;
	}
	error_exit("Error : not found envp", 1);
}

void	init_shell(int ac, char **av, char **envp, t_shell *shell)
{
	(void)ac;
	(void)av;
	shell->history = 0;
	shell->idx = 0;
	find_path(shell, envp);
}
Footer
