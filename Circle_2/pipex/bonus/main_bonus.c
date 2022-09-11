/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 00:35:16 by chanwjeo         ###   ########.fr       */
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
		exit_perror("dup2 stdin fail", 1);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		exit_perror("dup2 stdout fail", 1);
	close(std_in);
	close(std_out);
}

static void	pipex(t_env *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->n_cmd)
	{
		info->pid = fork();
		if (info->pid == -1)
			exit_perror("pid error", 1);
		if (info->pid == 0)
		{
			if (i == 0)
				control_fds(info->pipe_fd[0], info->i_fd, info->pipe_fd[1]);
			else if (i == info->n_cmd - 1)
				control_fds(info->pipe_fd[2 * i], info->pipe_fd[2 * i - 2], info->o_fd);
			else
				control_fds(info->pipe_fd[2 * i], info->pipe_fd[2 * i - 2], info->pipe_fd[2 * i + 1]);
			if (execve(info->cmd[i].path, info->cmd[i].cmd, info->envp) == -1)
				exit_perror("execve fail", info->result);
		}
		if (info->here_doc && i == 0)
			waitpid(info->pid, &status, 0);
	}
	waitpid(info->pid, &status, WNOHANG);
}

static void	init_info(t_env *info, int argc, char **argv, char **envp)
{
	int	i;

	ft_memset(info, 0, sizeof(t_env));
	info->result = 1;
	if (!ft_strncmp(argv[1], "here_doc", 8))
		info->here_doc = 1;
	info->n_cmd = argc - 3 - info->here_doc;
	info->pipe_fd = (int *)malloc(sizeof(int) * 2 * (info->n_cmd - 1));
	if (!info->pipe_fd)
		exit_perror("malloc error", 1);
	i = -1;
	while (++i < info->n_cmd)
		if (pipe(info->pipe_fd + 2 * i) < 0)
			free(info->pipe_fd);
	info->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc < args_in(argv[1]))
		exit_perror("wrong command count!", 1);
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argc - (&info)->here_doc, argv + (&info)->here_doc);
	pipex(&info);
	return (0);
}
