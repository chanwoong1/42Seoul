/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/08 01:41:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

static void	control_fds(int closed, int std_in, int std_out)
{
	close(closed);
	if (dup2(std_in, STDIN_FILENO) == -1)
		exit_perror("dup2 fail", 1);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		exit_perror("dup2 fail", 1);
	close(std_in);
	close(std_out);
}

static void	pipex(t_env *info)
{
	int		i;
	pid_t	pid;
	int		status;

	i = -1;
	while (++i < 2)
	{
		info->pid[i] = fork();
		if (info->pid[i] == -1)
			exit_perror("pid error", 1);
		if (pid == 0)
		{
			if (i == 0)
			{
				control_fds(info->pipe_fd[0], info->infile_fd, info->pipe_fd[1]);
				if (info->cmd[0].path != NULL)
					execve(info->cmd[0].path, info->cmd[0].cmd, info->envp);
				exit_perror(info->cmd[0].path, info->result);
			}
			else
				control_fds(info->pipe_fd[1], info->pipe_fd[0], info->outfile_fd);
				if (info->cmd[1].path != NULL)
					execve(info->cmd[1].path, info->cmd[1].cmd, info->envp);
				exit_perror(info->cmd[1].path, info->result);
		}
	}
	close(info->pipe_fd[0]);
	close(info->pipe_fd[1]);
	waitpid(info->pid[0], &status, 0);
	if (0 == (status & 0xff))
		return (status >> 8);
	return (status);
}

static void	init_info(t_env *info, int argc, char **envp)
{
	ft_memset(info, 0, sizeof(t_env));
	info->cmd = (t_cmd *)malloc(sizeof(t_cmd) * 2);
	if (!info->cmd)
		exit_perror("malloc error", 1);
	if (pipe(info->pipe_fd) == -1)
		exit_perror("pipe error", 1);
	info->pid[0] = 1;
	info->pid[1] = 1;
	info->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc != 5)
		exit_perror("wrong command count!", 1);
	init_info(&info, argc, envp);
	parse_cmd(&info, argv);
	pipex(&info);
	return (0);
}
