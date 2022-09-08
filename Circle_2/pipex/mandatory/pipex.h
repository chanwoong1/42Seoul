/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/08 13:29:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

# define FALSE		0
# define TRUE		1
# define FAIL		0
# define SUCCESS	1
# define ERROR		2

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}				t_cmd;

typedef struct s_env
{
	char			**envp;
	int				infile_fd;
	int				outfile_fd;
	int				result;
	char			**path;
	int				status;
	int				pipe_fd[2];
	pid_t			pid[2];
	struct s_cmd	*cmd;
}				t_env;

/* parse.c */
void	parse_cmd(t_env *info, char **argv);
void	check_cmd(t_env *info, char **argv);
void	find_awk_sed(char **argv, int i, t_env *info);
char	*get_cmd_argv(char **path, char *cmd);
char	*find_path(char **envp);

/* utils.c */
void	exit_perror(char *msg, int code);
void	split_free(char **to_free);

#endif
