/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:55:15 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/21 00:26:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Standard library */
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>

/** Readline library */
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"
#include "helper.h"
#include "../../include/builtin.h"

void	show_logo_2(void)
{
	const char	*orange;
	const char	*white;

	orange = "\033[38;5;208m";
	white = "\033[0m";
	printf("%s║   ██║   ██║████████║████████║██╔██╗██║██║ ████╗██████╗    ███"\
		"█████╗████████║██████╗  ██║      ██║        ║%s\n", orange, white);
	printf("%s║   ██║   ██║██╔═██╔═╝██╔═══██║██║╚═███║██║ ╚═██║██╔═══╝    ╚══"\
		"═══██║██╔═══██║██╔═══╝  ██║      ██║        ║%s\n", orange, white);
	printf("%s║   ████████║██║ ╚═██╗██║   ██║██║  ╚██║████████║████████╗  ███"\
		"█████║██║   ██║████████╗████████╗████████╗  ║%s\n", orange, white);
	printf("%s║   ╚═══════╝╚═╝   ╚═╝╚═╝   ╚═╝╚═╝   ╚═╝╚═══════╝╚═══════╝  ╚══"\
		"═════╝╚═╝   ╚═╝╚═══════╝╚═══════╝╚═══════╝  ║%s\n", orange, white);
	printf("%s║                                                              "\
		"                                            ║%s\n", orange, white);
	printf("%s║                                                              "\
		"               .created by yje & chanwjeo   ║%s\n", orange, white);
	printf("%s║                                                              "\
		"                                            ║%s\n", orange, white);
	printf("%s╚══════════════════════════════════════════════════════════════"\
		"════════════════════════════════════════════╝%s\n", orange, white);
	printf("\n");
}

void	show_logo_1(void)
{
	const char	*orange;
	const char	*red;
	const char	*yellow;
	const char	*white;

	orange = "\033[38;5;208m";
	red = "\033[31m";
	yellow = "\033[93m";
	white = "\033[0m";
	printf("%s╔══════════════════════════════════════════════════════════════"\
		"════════════════════════════════════════════╗%s\n", orange, white);
	printf("%s║                                                              "\
		"                                            ║%s\n", orange, white);
	printf("%s║   Welcome to 42 minishell project. %sLEE %s& %sGUN           "\
		"                                                  %s║\n" \
		, orange, red, orange, yellow, orange);
	printf("%s║                                                              "\
		"                                            ║%s\n", orange, white);
	printf("%s║                                                              "\
		"                                            ║%s\n", orange, white);
	printf("%s║   ████████╗████████╗████████╗██╗   ██╗████████╗████████╗  ███"\
		"█████╗██╗   ██╗████████╗██╗      ██╗        ║%s\n", orange, white);
	printf("%s║   ██╔═══██║██╔═══██║██╔═══██║███╗  ██║██╔═════╝██╔═════╝  ██╔"\
		"═════╝██║   ██║██╔═════╝██║      ██║        ║%s\n", orange, white);
}

void	show_shell_logo(void)
{
	show_logo_1();
	show_logo_2();
}

void	make_history(char *line, t_history *history)
{
	if (history->idx == 1)
	{
		history->history = ft_strdup_without_newline(ft_itoa(history->idx));
		history->history = ft_strjoin_all(4, history->history, " ", line, "\n");
		history->idx++;
	}
	else
	{
		history->history = ft_strjoin_all(5, history->history, history->idx, " ", line, "\n");
		history->idx++;
	}
}

/** show prompt_messege + readline */
char	*readline_prompt(t_shell_config *config, t_history *history)
{
	t_string	*prompt;
	char		*line;

	line = NULL;
	prompt = new_string(64);
	prompt->f_append(prompt, "\033[38;5;208m");
	prompt->f_append(prompt, get_environ_value("USER", *config->envp));
	prompt->f_append(prompt, ":");
	prompt->f_append(prompt, get_environ_value("PWD", *config->envp));
	prompt->f_replace_all(prompt, \
			get_environ_value("HOME", *config->envp), "~");
	prompt->f_append(prompt, "\033[0m");
	prompt->f_append(prompt, "$ ");
	line = readline(prompt->text);
	delete_string(&prompt);
	make_history(line, history);
	return (line);
}
