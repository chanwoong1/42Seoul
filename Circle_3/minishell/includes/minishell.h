/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:31:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/02 14:45:17 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h> 
# include <readline/history.h>
# include <readline/readline.h>

/* libft */
# include "../libft/libft.h"

/* get_next_line */
# include "../gnl/get_next_line.h"

typedef struct s_history
{
	char *history;	
}	t_history;

typedef struct s_parse
{
	char	**envp;
	int		i_fd;
	int		o_fd;
	int		here_doc;
	int		quote;
	int		num_of_split_cmd;
}	t_parse;

/*
prompt
*/

/* prompt.c */

/*
utils
*/

/* util_free.c */
void	free_all_split(char **split);

/* util_print.c */
void	error_exit(char *msg, int code);

/*
parse
*/

/* init_parse.c */
void	init_cmd_parse(t_parse **cmd_parse, char **envp, char *cmd);

/* history.c */
void	save_history(t_history *history, char *cmd, int idx);

/* heredoc.c */
void	here_doc(char *limiter);

/* fd.c */
void	get_i_fd(t_parse **cmd_parse, char **cmd_split);
void	get_o_fd(t_parse **cmd_parse, char **cmd_split);

# endif
