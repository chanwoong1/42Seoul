/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 18:35:45 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	init_info(t_env *info, int argc, char **argv, char **envp)
{
	int	i;

	ft_memset(info, 0, sizeof(t_env));
	info->result = 1;
	info->envp = envp;
	get_fd(info, argc, argv);
	info->n_cmd = argc - 3 - info->here_doc;
	info->pipe_fd = (int *)malloc(sizeof(int) * 2 * (info->n_cmd - 1));
	if (!info->pipe_fd)
		exit_perror("malloc error", 1);
	i = -1;
	while (++i < info->n_cmd - 1)
	{
		if (pipe(info->pipe_fd + 2 * i) < 0)
		{
			free(info->pipe_fd);
			exit_perror(ERR_PIPE, 1);
		}
	}
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
		else if (p.idx == p.n_cmd - 1)
			sub_dup2(p.pipe_fd[2 * p.idx - 2], p.o_fd);
		else
			sub_dup2(p.pipe_fd[2 * p.idx - 2], p.pipe_fd[2 * p.idx + 1]);
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
