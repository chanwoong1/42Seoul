/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:51:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 09:36:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

void	parse_cmd(t_env *info, int argc, char **argv)
{
	char	*temp_path;

	info->cmd = (t_cmd *)malloc(sizeof(t_cmd) * (argc - 3));
	if (!info->cmd)
		exit_perror("malloc error", 1);
	temp_path = find_path(info->envp);
	info->path = ft_split(temp_path, ':');
	check_cmd(info, argv);
	free(temp_path);
}

void	check_cmd(t_env *info, char **argv)
{
	int	i;

	i = -1 + info->here_doc;
	while (++i < info->n_cmd)
	{
		while (*(argv[i + 2]) == ' ')
			argv[i + 2]++;
		if (!ft_strncmp(argv[i + 2], "awk ", 4) || \
			!ft_strncmp(argv[i + 2], "sed ", 4))
			find_awk_sed(argv, i, info);
		else
			info->cmd[i].cmd = ft_split(argv[i + 2], ' ');
		info->cmd[i].path = get_cmd_argv(info->path, info->cmd[i].cmd[0]);
		if (info->cmd[i].path == NULL)
			info->result = 127;
	}
	if (info->result == 127)
		perror("command not found");
}

void	find_awk_sed(char **argv, int i, t_env *info)
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
		split_free(&(info->cmd[i].cmd[++j]));
	if (ft_strncmp(info->cmd[i].cmd[tmp], "\'", 1) == 0)
		tmp_info = ft_split(argv[i + 2], '\'');
	else
		tmp_info = ft_split(argv[i + 2], '\"');
	split_free(&(info->cmd[i].cmd[tmp]));
	info->cmd[i].cmd[tmp] = ft_strdup(tmp_info[1]);
	info->cmd[i].cmd[tmp + 1] = NULL;
	tmp = 0;
	while (tmp_info[tmp])
		split_free(&tmp_info[tmp++]);
	free(tmp_info);
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
