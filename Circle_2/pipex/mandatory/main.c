/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 15:37:35 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_info(t_env *info, int argc, char **argv, char **envp)
{
	ft_memset(info, 0, sizeof(t_env));
	info->result = 1;
	info->envp = envp;
	get_fd(info, argc, argv);
	if (pipe(info->pipe_fd) < 0)
		exit_perror(ERR_PIPE, 1);
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	child(t_env p)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.idx == 0)
			sub_dup2(p.i_fd, p.pipe_fd[1]);
		else if (p.idx == 1)
			sub_dup2(p.pipe_fd[0], p.o_fd);
		close_pipes(&p);
		if (!p.cmd->path)
		{
			perror(p.cmd->cmd[0]);
			exit(1);
		}
		execve(p.cmd[p.idx].path, p.cmd[p.idx].cmd, p.envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc != 5)
		usage();
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argc, argv);
	info.idx = -1;
	while (++(info.idx) < 2)
		child(info);
	close_pipes(&info);
	waitpid(-1, NULL, 0);
	parent_free(&info);
	return (0);
}
