/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/02 11:31:07 by chanwjeo         ###   ########.fr       */
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

int	set_cmd(t_env *info, t_cmd *ps)
{
    int	i;
    char *temp_path;
    char *temp_cpath;

    i = 0;
    while (info->path[i])
    {
        temp_path = ft_strjoin(info->path[i], "/");
        temp_cpath = ft_strjoin(temp_path, ps->cmd[0]);
        if (access(temp_cpath, F_OK) == 0)
        {
            ps->path = ft_strdup(temp_cpath);
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
        if (info->ps[i].slash == FALSE)
        {
            if (set_cmd(info, &info->ps[i]) == ERROR)
                exit_err("command not found!\n");
        }
        else
            info->ps[i].path = ft_strdup(info->ps[i].cmd[0]);
        i++;
    }
}

void	check_parse(t_env *info)
{
    info->infile_fd = open(info->infile, O_RDWR);
    if (info->infile_fd < 0)
        exit_perror("not valid infile!", 1);
    info->outfile_fd = open(info->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (info->outfile_fd < 0)
	{
		close(info->infile_fd);
        exit_perror("not valid outfile!", 1);
	}
    check_commands(info);
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

void	check_slash(t_cmd *ps, const char *temp)
{
    if (ft_strncmp(temp, "/", 1) == 0
        || ft_strncmp(temp, "./", 2) == 0 || ft_strncmp(temp, "../", 3) == 0)
        ps->slash = TRUE;
}

void	parse_cmd(t_env *info, char **argv, char **envp)
{
    char	*temp_path;

	info->result = 1;
    info->infile = ft_strdup(argv[1]);
	info->ps = (t_cmd *)malloc(sizeof(t_cmd) * 2);
	if (!info->ps)
		exit_err("malloc error");
    info->ps[0].cmd = ft_split(argv[2], ' ');
    check_slash(&info->ps[0], argv[2]);
    info->ps[1].cmd = ft_split(argv[3], ' ');
    check_slash(&info->ps[1], argv[3]);
	if (info->ps[0].cmd[0] == 0 || info->ps[1].cmd[0] == 0)
		exit_perror("command not found", 127);
    info->outfile = ft_strdup(argv[4]);
    temp_path = find_path(envp);
    if (temp_path == NULL && (info->ps[0].slash == FALSE || info->ps[1].slash == FALSE))
        exit_perror("wrong path!", 127);
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

void	pipex(t_env *info, char **envp)
{
	if (info->pid == -1)
		exit_err("pid error");
	if (info->pid == 0)
	{
		control_fds(info->pipe_fd[0], info->infile_fd, info->pipe_fd[1]);
		if (execve(info->ps[0].path, info->ps[0].cmd, envp) == -1)
			exit_perror("execve fail", info->result);
	}
	else
	{
		control_fds(info->pipe_fd[1], info->pipe_fd[0], info->outfile_fd);
		waitpid(info->pid, NULL, WNOHANG);
		if (execve(info->ps[1].path, info->ps[1].cmd, envp) == -1)
			exit_perror("execve fail", info->result);
	}
}

void	init_info(t_env *info, char **envp)
{
	ft_memset(info, 0, sizeof(t_env));
	info->pid = fork();
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
	parse_cmd(&info, argv, envp);
	check_parse(&info);
	pipex(&info, envp);
	return (0);
}
