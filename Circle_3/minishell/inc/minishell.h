/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:34:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 09:56:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <stdio.h>
# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h> 
# include <readline/history.h>
# include <readline/readline.h>
# include "libft.h"
# include "../src/gnl/get_next_line.h"

# define IS_QUOTE(x) (x == '"' || x == '\'')

char					**g_envp;

typedef struct s_shell
{
	char	*history;
	char	**path;
	int		idx;
}	t_shell;

typedef struct s_parse
{
	char	**envp;
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
** src/cd_builtin.c
*/
void					change_dir(char *path, int print_path);
int						cd_builtin(char **command);

/*
** src/display_prompt_msg.c
*/
void					exit_shell(void);
char					*parse_home_path(char *path, int reverse_parse);
void					display_prompt_msg(void);

/*
** src/echo_builtin.c
*/
int						echo_builtin(char **command);

/*
** src/exec_command.c
*/
int						exec_command(char **command);

/*
** src/setenv_builtin.c
*/
int						find_env_var(char *var);
char					*get_env_var(char *var);
char					**realloc_envv(int new_size);
void					set_env_var(char *key, char *value);
int						setenv_builtin(char **command);
int						setenv_builtin(char **args);

/*
** src/signal_handler.c
*/
void					signal_handler(int signo);
void					proc_signal_handler(int signo);

/*
** src/unsetenv_builtin.c
*/
void					print_env(void);
void					init_envv(int ac, char **av, char **envv);
int						unsetenv_builtin(char **command);
#endif

void	init_shell(int ac, char **av, char **envp, t_shell *shell);
void	save_history(t_shell *shell, char *cmd);

void	here_doc(char *limiter);