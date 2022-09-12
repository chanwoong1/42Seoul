/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 09:55:16 by chanwjeo         ###   ########.fr       */
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
# define BUFFER_SIZE 42
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}				t_cmd;

typedef struct s_env
{
	char			**envp;
	int				n_cmd;
	int				here_doc;
	char			**hd_cmd;
	int				idx;
	int				i_fd;
	int				o_fd;
	int				*pipe_fd;
	int				result;
	char			**path;
	pid_t			pid;
	struct s_cmd	*cmd;
}				t_env;

/* parse_bonus.c */
void	parse_cmd(t_env *info, int argc, char **argv);
void	check_cmd(t_env *info, char **argv);
void	find_awk_sed(char **argv, int i, t_env *info);
char	*get_cmd_argv(char **path, char *cmd);
char	*find_path(char **envp);

/* utils_bonus.c */
void	exit_perror(char *msg, int code);
void	split_free(char **to_free);
void	free_fd_arr(int	**arr, int i);
void	usage(void);
int		open_file(char *argv, int i);

/* heredoc_bonus.c */
int		args_in(char *arg);
void	here_doc(char *argv, t_env *info);

/* gnl_bonus.c */
char	*get_next_line(int fd);

/* gnl_utils_bonus.c */
int		gnl_strlen(const char *s);
int		gnl_strchr(char *s);
char	*gnl_strjoin(char *s1, char *s2);

#endif
