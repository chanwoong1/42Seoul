/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/08 22:23:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
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
	int	i;

	i = -1;
	info->pid = (pid_t *)malloc(sizeof(pid_t) * (info->argc - info->here_doc - 3));
	if (!info->pid)

	info->pid = fork();
	if (info->pid == -1)
		exit_perror("pid error", 1);
	else if (info->pid == 0)
	{
		while (++i < info->argc - info->here_doc - 3)
		{
			control_fds(info->pipe_fd[0], info->i_fd, info->pipe_fd[1]);
			info->result = execve(info->cmd[i].path, info->cmd[i].cmd, info->envp)
			if (info->result == -1)
				exit_perror("execve fail", info->result);
		}
		i = 0;
		while (i < px->cmd_num - 1)
		{
			if (i != idx && i != idx - 1)
			{
				close(px->pipefd[i][0]);
				close(px->pipefd[i][1]);
			}
			i++;
		}
		close(px->pipefd[idx - 1][1]);
		close(px->pipefd[idx][0]);
		if (dup2(px->pipefd[idx - 1][0], 0) == -1)
			print_error(2, NULL);
		close(px->pipefd[idx - 1][0]);
		if (dup2(px->pipefd[idx][1], 1) == -1)
			print_error(2, NULL);
		close(px->pipefd[idx][1]);
		if (node->cmd_path[0] != NULL)
			execve(node->cmd_path[0], node->cmd, px->ev);
		print_error(1, node->cmd[0]);
	}
	else
	{
		waitpid(info->pid, NULL, WNOHANG);
		exit(info->result);
	}
}

static void	init_info(t_env *info, int argc, char **argv, char **envp)
{
	ft_memset(info, 0, sizeof(t_env));
	if (!ft_strncmp(argv[1], "here_doc", 8))
		info->here_doc = 1;
	info->pipe_fd = (int **)malloc(sizeof(int *) * argc - info->here_doc - 3);
	if (!info->pipe_fd)

	if (pipe(info->pipe_fd) == -1)
		exit_perror("pipe error", 1);
	info->envp = envp;
	info->argc = argc;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc < 5)
		exit_perror("wrong command count!", 1);
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argv);
	pipex(&info);
	return (0);
}
