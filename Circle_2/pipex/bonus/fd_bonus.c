/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:56:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/17 21:11:31 by chanwjeo         ###   ########.fr       */
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

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		exit_perror(ERR_HEREDOC, info->result);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			exit(info->result);
		if (!ft_strncmp(argv, line, ft_strlen(argv)) \
			&& ft_strlen(argv) == (ft_strlen(line) - 1))
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
}

void	get_fd(t_env *info, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		info->here_doc = 1;
		here_doc(argv[2], info);
		info->i_fd = open(".heredoc_tmp", O_RDONLY);
		if (info->i_fd < 0)
		{
			unlink(".heredoc_tmp");
			exit_perror(ERR_HEREDOC, info->result);
		}
	}
	else
	{
		info->i_fd = open(argv[1], O_RDONLY);
		if (info->i_fd < 0)
			perror("not valid infile");
	}
	if (info->here_doc)
		info->o_fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		info->o_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->o_fd < 0)
		exit_perror("not valid outfile", 1);
}

void	parent_free(t_env *info)
{
	close(info->i_fd);
	close(info->o_fd);
	if (info->here_doc)
		unlink(".heredoc_tmp");
	free(info->pipe_fd);
}
