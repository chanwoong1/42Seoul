/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/07 01:13:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	exit_perror(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	my_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
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
		if (info->cmd[i].slash == FALSE)
		{
			if (set_cmd(info, &info->cmd[i]) == ERROR)
			{
				perror("command not found!");
				info->result = 127;
				break ;
			}
		}
		else
			info->cmd[i].path = ft_strdup(info->cmd[i].cmd[0]);
		i++;
	}
}

char	*get_cmd_argv(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	path_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
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

void	awk_sed(char **argv, int i, t_env *info)
{
	int		j;
	int		tmp;
	char	**tmp_info;

	j = 0;
	info->cmd[i].cmd = ft_split(argv[i + 2], ' ');
	while (ft_strncmp(info->cmd[i].cmd[j], "\'", 1) != 0 && \
		ft_strncmp(info->cmd[i].cmd[j], "\"", 1) != 0 && info->cmd[i].cmd[j])
		j++;
	tmp = j;
	if (info->cmd[i].cmd[j] == 0)
		return ;
	while (info->cmd[i].cmd[j])
		my_free(&(info->cmd[i].cmd[++j]));
	if (ft_strncmp(info->cmd[i].cmd[tmp], "\'", 1) == 0)
		tmp_info = ft_split(argv[i + 2], '\'');
	else
		tmp_info = ft_split(argv[i + 2], '\"');
	my_free(&(info->cmd[i].cmd[tmp]));
	info->cmd[i].cmd[tmp] = ft_strdup(tmp_info[1]);
	info->cmd[i].cmd[tmp + 1] = NULL;
	tmp = 0;
	while (tmp_info[tmp])
		my_free(&tmp_info[tmp++]);
	free(tmp_info);
}

void	check_cmd(t_env *info, char **argv)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while (*(argv[i + 2]) == ' ')
			argv[i + 2]++;
		if (!ft_strncmp(argv[i + 2], "awk ", 4) || \
			!ft_strncmp(argv[i + 2], "sed ", 4))
			awk_sed(argv, i, info);
		else
		{
			info->cmd[i].cmd = ft_split(argv[i + 2], ' ');
		}
		i++;
	}
	check_slash(&info->cmd[0], argv[2]);
	check_slash(&info->cmd[1], argv[3]);
	info->cmd[0].path = get_cmd_argv(info->path, info->cmd[0].cmd[0]);
	info->cmd[1].path = get_cmd_argv(info->path, info->cmd[1].cmd[0]);
	if (info->cmd[0].path == NULL || info->cmd[1].path == NULL)
	{
		info->result = 127;
		perror("command not found");
	}
}

void	parse_cmd(t_env *info, char **argv)
{
	char	*temp_path;

	info->result = 1;
	info->infile_fd = open(argv[1], O_RDONLY);
	if (info->infile_fd < 0)
		perror("not valid infile");
	info->outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd < 0)
		exit_perror("not valid outfile", 1);
	info->cmd = (t_cmd *)malloc(sizeof(t_cmd) * 2);
	if (!info->cmd)
		exit_perror("malloc error", 1);
	temp_path = find_path(info->envp);
	info->path = ft_split(temp_path, ':');
	int i = -1;
	while (++i < 20)
		printf("info->path[%d] : %s\n", i, info->path[i]);
	check_cmd(info, argv);
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
		exit_perror("pid error", 1);
	else if (info->pid == 0)
	{
		if (info->infile_fd != -1)
		{
			control_fds(info->pipe_fd[0], info->infile_fd, info->pipe_fd[1]);
			if (execve(info->cmd[0].path, info->cmd[0].cmd, info->envp) == -1)
				exit_perror("execve fail", info->result);
		}
	}
	else
	{
		if (info->outfile_fd != -1)
		{
			control_fds(info->pipe_fd[1], info->pipe_fd[0], info->outfile_fd);
			waitpid(info->pid, NULL, WNOHANG);
			if (execve(info->cmd[1].path, info->cmd[1].cmd, info->envp) == -1)
				exit_perror("execve fail", info->result);
		}
	}
}

void	init_info(t_env *info, char **envp)
{

	ft_memset(info, 0, sizeof(t_env));
	if (pipe(info->pipe_fd) == -1)
		exit_perror("pipe error", 1);
	info->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	int i = -1;
	while (envp[++i])
		printf("envp[%d] : %s\n", i, envp[i]);
	if (argc != 5)
		exit_perror("wrong command count!", 1);
	init_info(&info, envp);
	parse_cmd(&info, argv);
	pipex(&info);
	return (0);
}
