/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:50:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/01 22:19:30 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

# define FALSE		0
# define TRUE		1
# define FAIL		0
# define SUCCESS	1
# define ERROR		2

typedef struct	s_cmd
{
    char	**cmd;
	char	*path;
    int		slash;
}				t_cmd;
typedef struct  s_env
{
	char			**envp;
	char			*infile;
	char			*outfile;
	int				infile_fd;
	int				outfile_fd;
	int				pipe_fd[2];
	char			**path;
	pid_t			pid;
	struct s_cmd	*ps;
}				t_env;

#endif
