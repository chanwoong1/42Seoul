/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:56:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 11:19:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	args_in(char *arg)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
		return (6);
	else
		return (5);
}

void	here_doc(char *argv, t_env *info)
{
	int		file;
	char	*line;

	info->here_doc = 1;
	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		exit_perror(ERR_HEREDOC, info->result);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			exit(info->result);
		if (!ft_strncmp(argv, line, ft_strlen(argv) + 1))
			break ;
		write(file, line, ft_strlen(line));
		write(file, "\n", 1);
		free(line);
	}
	free(line);
	close(file);
	info->i_fd = open(".heredoc_tmp", O_RDONLY);
	if (info->i_fd < 0)
	{
		unlink(".heredoc_tmp");
		exit_perror(ERR_HEREDOC, info->result);
	}
}
