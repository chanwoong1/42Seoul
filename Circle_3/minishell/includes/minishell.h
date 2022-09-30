/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:31:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/01 07:43:54 by chanwjeo         ###   ########.fr       */
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

typedef struct s_parse
{
	char	**envp;
	int		i_fd;
	int		o_fd;
	int		here_doc;
}	t_parse;

# endif
