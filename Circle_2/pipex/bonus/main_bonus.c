/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/11 17:40:29 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

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
	int	i;
	int	status;

	i = -1;
	while (++i < info->argc - 3)
	{
		info->pid = fork();
		if (info->pid == -1)
			exit_perror("pid error", 1);
		if (info->pid == 0)
		{
			if (i == 0)
				control_fds(info->pipe_fd[i][0], info->i_fd, info->pipe_fd[i][1]);
			else if (i == info->argc - 4)
				control_fds(info->pipe_fd[i][0], info->pipe_fd[i - 1][0], info->o_fd);
			else
				control_fds(info->pipe_fd[i][0], info->pipe_fd[i - 1][0], info->pipe_fd[i][1]);
			if (execve(info->cmd[i].path, info->cmd[i].cmd, info->envp) == -1)
				exit_perror("execve fail", info->result);
		}
		else
		{
			if (i < info->argc - 4)
				control_fds(info->pipe_fd[i][1], info->pipe_fd[i][0], info->pipe_fd[i + 1][1]);
			waitpid(info->pid, NULL, 0);
		}
		if (info->here_doc && i == 0)
			waitpid(info->pid, &status, 0);
	}
	waitpid(info->pid, &status, WNOHANG);
	exit(info->result);
}

static void	init_info(t_env *info, int argc, char **argv, char **envp)
{
	int	i;

	ft_memset(info, 0, sizeof(t_env));
	if (!ft_strncmp(argv[1], "here_doc", 8))
		info->here_doc = 1;
	info->argc = argc - info->here_doc;
	info->pipe_fd = (int **)malloc(sizeof(int *) * info->argc - 3);
	if (!info->pipe_fd)
		exit_perror("malloc error", 1);
	i = 0;
	while (i < info->argc - 3)
	{
		info->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!info->pipe_fd[i])
		{
			free_fd_arr(info->pipe_fd, i);
			exit_perror("malloc error", 1);
		}
		if (pipe(info->pipe_fd[i]) == -1)
			exit_perror("pipe error", 1);
		i++;
	}
	info->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc < 5)
		exit_perror("wrong command count!", 1);
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argc - (&info)->here_doc, argv + (&info)->here_doc);
	pipex(&info);
	return (0);
}
