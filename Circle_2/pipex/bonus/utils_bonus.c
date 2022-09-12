/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:59:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 11:19:13 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	exit_perror(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	split_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

void	free_fd_arr(int	**arr, int i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
}

void	usage(void)
{
	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}
