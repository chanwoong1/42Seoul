/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/07 21:27:45 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int				argc;
	int				here_doc;
	char			**hd_cmd;
	int				i_fd;
	int				o_fd;
	int				**pipe_fd;
	int				result;
	char			**path;
	pid_t			*pid;
	struct s_cmd	*cmd;
}				t_env;

/* parse_bonus.c */
void	parse_cmd(t_env *info, char **argv);
void	check_cmd(t_env *info, char **argv);
void	find_awk_sed(char **argv, int i, t_env *info);
char	*get_cmd_argv(char **path, char *cmd);
char	*find_path(char **envp);

/* utils_bonus.c */
void	exit_perror(char *msg, int code);
void	split_free(char **to_free);

/* heredoc_bonus.c */
void	here_doc_parse(t_env *info);

#endif