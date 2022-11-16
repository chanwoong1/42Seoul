/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:49:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 09:57:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minishell.h"

void	here_doc(char *limiter)
{
	int		file;
	char	*line;

	unlink("./heredoc/heredoc_tmp");
	file = open("./heredoc/heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		exit_shell();
		// error_exit("heredoc fail, try one more time.", 1);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			exit(1);
		if (!ft_strncmp(limiter, line, ft_strlen(limiter)) \
			&& ft_strlen(limiter) == (ft_strlen(line) - 1))
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
}