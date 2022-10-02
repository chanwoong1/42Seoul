/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:31:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/02 17:59:55 by chanwjeo         ###   ########.fr       */
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

typedef struct s_shell
{
	char	*history;
	char	**path;
	int		idx;
}	t_shell;

typedef struct s_parse
{
	int		s_quote;
	int		d_quote;
	int		bracket;
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

/* init_shell.c */
void	init_shell(t_shell *shell, char **argv, char **envp);

/* init_parse.c */
void	init_cmd_parse(t_parse **cmd_parse, t_shell *shell, char *cmd);

/* history.c */
void	save_history(t_shell *shell, char *cmd, int idx);

/* fd.c */
void	get_i_fd(t_parse **cmd_parse, char **cmd_split);
void	get_o_fd(t_parse **cmd_parse, char **cmd_split);

/*
heredoc
*/

/* heredoc.c */
void	here_doc(char *limiter);

# endif
