/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 11:19:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

// static void	control_fds(int closed, int std_in, int std_out)
// {
// 	close(closed);
// 	if (dup2(std_in, STDIN_FILENO) == -1)
// 		exit_perror("dup2 stdin fail", 1);
// 	if (dup2(std_out, STDOUT_FILENO) == -1)
// 		exit_perror("dup2 stdout fail", 1);
// 	close(std_in);
// 	close(std_out);
// }

// static void	pipex(t_env *info)
// {
// 	int	i;
// 	int	status;

// 	i = -1;
// 	while (++i < info->n_cmd)
// 	{
// 		info->pid = fork();
// 		if (info->pid == -1)
// 			exit_perror("pid error", 1);
// 		if (info->pid == 0)
// 		{
// 			if (i == 0)
// 				control_fds(info->pipe_fd[0], info->i_fd, info->pipe_fd[1]);
// 			else if (i == info->n_cmd - 1)
// 				control_fds(info->pipe_fd[2 * i], info->pipe_fd[2 * i - 2], info->o_fd);
// 			else
// 				control_fds(info->pipe_fd[2 * i], info->pipe_fd[2 * i - 2], info->pipe_fd[2 * i + 1]);
// 			if (execve(info->cmd[i].path, info->cmd[i].cmd, info->envp) == -1)
// 				exit_perror("execve fail", info->result);
// 		}
// 		if (info->here_doc && i == 0)
// 			waitpid(info->pid, &status, 0);
// 	}
// 	waitpid(info->pid, &status, WNOHANG);
// }

static void	get_fd(t_env *info, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
		here_doc(argv[2], info);
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

static void	init_info(t_env *info, int argc, char **argv, char **envp)
{
	int	i;

	ft_memset(info, 0, sizeof(t_env));
	info->result = 1;
	info->n_cmd = argc - 3 - info->here_doc;
	info->envp = envp;
	get_fd(info, argc, argv);
	info->pipe_fd = (int *)malloc(sizeof(int) * 2 * (info->n_cmd - 1));
	if (!info->pipe_fd)
		exit_perror("malloc error", 1);
	i = -1;
	while (++i < info->n_cmd)
	{
		if (pipe(info->pipe_fd + 2 * i) < 0)
		{
			free(info->pipe_fd);
			exit_perror("malloc error", 1);
		}
	}
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	close_pipes(t_env *info)
{
	int	i;

	i = 0;
	while (i < 2 * (info->n_cmd - 1))
	{
		close(info->pipe_fd[i]);
		i++;
	}
}

// void	child_free(t_env *info)
// {
// 	int	i;

// 	i = 0;
// 	while (info->cmd[i].path)
// 	{
// 		free(info->cmd[i].cmd);
// 		i++;
// 	}
// 	free(pipex->cmd_args);
// 	free(pipex->cmd);
// }

void	parent_free(t_env *info)
{
	// int	i;

	// i = 0;
	close(info->i_fd);
	close(info->o_fd);
	if (info->here_doc)
		unlink(".heredoc_tmp");
	// while (info->cmd_paths[i])
	// {
	// 	free(pipex->cmd_paths[i]);
	// 	i++;
	// }
	// free(pipex->cmd_paths);
	free(info->pipe_fd);
}

void	child(t_env p)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.idx == 0)
			sub_dup2(p.i_fd, p.pipe_fd[1]);
		else if (p.idx == p.n_cmd - 1)
			sub_dup2(p.pipe_fd[2 * p.idx - 2], p.o_fd);
		else
			sub_dup2(p.pipe_fd[2 * p.idx - 2], p.pipe_fd[2 * p.idx + 1]);
		close_pipes(&p);
		if (!p.cmd->path)
		{
			perror(p.cmd->cmd[0]);
			// child_free(&p);
			exit(1);
		}
		execve(p.cmd[p.idx].path, p.cmd[p.idx].cmd, p.envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc < args_in(argv[1]))
		usage();
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argc - (&info)->here_doc, argv + (&info)->here_doc);
	info.idx = -1;
	while (++(info.idx) < info.n_cmd)
		child(info);
	close_pipes(&info);
	waitpid(-1, NULL, 0);
	parent_free(&info);
	return (0);
}
