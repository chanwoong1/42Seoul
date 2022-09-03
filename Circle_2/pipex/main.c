/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/03 14:14:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	exit_err(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	exit_perror(char *msg, int code)
{
	perror(msg);
	exit(code);
}

int	set_cmd(t_env *info, t_cmd *cmd)
{
	int	i;
	char *temp_path;
	char *temp_cpath;

	i = 0;
	while (info->path[i])
	{
		temp_path = ft_strjoin(info->path[i], "/");
		temp_cpath = ft_strjoin(temp_path, cmd->cmd[0]);
		if (access(temp_cpath, F_OK) == 0)
		{
			cmd->path = ft_strdup(temp_cpath);
			free(temp_path);
			free(temp_cpath);
			return (SUCCESS);
		}
		free(temp_path);
		free(temp_cpath);
		i++;
	}
	return (ERROR);
}

void	check_commands(t_env *info)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (info->cmd[i].slash == FALSE) //cmd[0] -> cmd1 (grep a1) , cmd[1] -> cmd2 (wc -w)
		{
			if (set_cmd(info, &info->cmd[i]) == ERROR)
				exit_err("command not found!\n");
		}
		else
			info->cmd[i].path = ft_strdup(info->cmd[i].cmd[0]);
		i++;
	}
}

char	*find_path(char **envp)
{
	int		i;
	char	*ret_path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			ret_path = ft_strdup(envp[i] + 5);
			return (ret_path);
		}
		i++;
	}
	return (NULL);
}

void	check_slash(t_cmd *cmd, const char *temp)
{
	if (ft_strncmp(temp, "/", 1) == 0
		|| ft_strncmp(temp, "./", 2) == 0 || ft_strncmp(temp, "../", 3) == 0)
		cmd->slash = TRUE;
}

void	parse_cmd(t_env *info, char **argv)
{
	char	*temp_path;

	info->result = 1;
	info->infile_fd = open(argv[1], O_RDONLY);
	if (info->infile_fd < 0)
		exit_perror("not valid infile!", 1);
	info->outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd < 0)
		exit_perror("not valid outfile!", 1);
	info->cmd = (t_cmd *)malloc(sizeof(t_cmd) * 2);
	if (!info->cmd)
		exit_err("malloc error");
	info->cmd[0].cmd = ft_split(argv[2], ' ');
	info->cmd[1].cmd = ft_split(argv[3], ' ');
	check_slash(&info->cmd[0], argv[2]);
	check_slash(&info->cmd[1], argv[3]);
	if (info->cmd[0].cmd == NULL || info->cmd[1].cmd == NULL)
		exit_perror("command not found", 127);
	temp_path = find_path(info->envp);
	if (temp_path == NULL && (info->cmd[0].slash == FALSE || info->cmd[1].slash == FALSE))
		exit_perror("PATH error", 127);
	info->path = ft_split(temp_path, ':');
	free(temp_path);
}

void	control_fds(int closed, int std_in, int std_out)
{
	close(closed);
	if (dup2(std_in, STDIN_FILENO) == -1)
		exit_perror("dup2 fail", 1);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		exit_perror("dup2 fail", 1);
	close(std_in);
	close(std_out);
}

void	pipex(t_env *info)
{
	info->pid = fork();
	if (info->pid == -1)
		exit_err("pid error");
	else if (info->pid == 0)
	{
		control_fds(info->pipe_fd[0], info->infile_fd, info->pipe_fd[1]);
		if (execve(info->cmd[0].path, info->cmd[0].cmd, info->envp) == -1)
			exit_perror("execve fail", info->result);
	}
	else
	{
		control_fds(info->pipe_fd[1], info->pipe_fd[0], info->outfile_fd);
		waitpid(info->pid, NULL, WNOHANG);
		if (execve(info->cmd[1].path, info->cmd[1].cmd, info->envp) == -1)
			exit_perror("execve fail", info->result);
	}
}

void	init_info(t_env *info, char **envp)
{
	ft_memset(info, 0, sizeof(t_env));
	if (pipe(info->pipe_fd) == -1)
		exit_err("pipe error");
	info->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc != 5)
		exit_err("wrong command count!");
	init_info(&info, envp);
	parse_cmd(&info, argv);
	check_commands(&info);
	pipex(&info);
	return (0);
}
