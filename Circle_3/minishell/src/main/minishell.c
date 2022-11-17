/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:02:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 20:08:35 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"
#include "helper.h"
#include "signal.h"
#include "heredoc.h"
#include "../../include/execute.h"

int	g_is_sig_interupt = false;

int	run_shell(char *line, t_shell_config *config)
{
	t_list	*tokens;
	t_tree	*syntax_tree;

	tokens = tokenize(line);
	if (tokens == NULL)
		return (CMD_KEEP_RUNNING);
	if (set_heredoc(tokens) == ERROR)
	{
		ft_lstclear(&tokens, delete_token);
		return (CMD_KEEP_RUNNING);
	}
	syntax_tree = parse(tokens);
	if (syntax_tree == NULL)
	{
		free(tokens);
		return (CMD_KEEP_RUNNING);
	}
	return (execute(syntax_tree, config));
}

void	shell_loop(t_shell_config *config)
{
	char	*line;

	while (true)
	{
		line = readline_prompt(config);
		if (line == NULL)
		{
			printf("exit\n");
			exit(-1);
		}
		else if (line != NULL && *line != '\0')
			add_history(line);
		else
		{
			free(line);
			line = NULL;
			continue ;
		}
		run_shell(line, config);
		free(line);
		line = NULL;
	}
}

void	load_shell_config(t_shell_config *shell_config, char **env)
{
	shell_config->envp = ft_calloc(1, sizeof(size_t));
	*shell_config->envp = new_environ(env);
	shell_config->stdin_backup = dup(STDIN_FILENO);
	shell_config->stdout_backup = dup(STDOUT_FILENO);
	shell_config->last_cmd_pid = 0;
	shell_config->last_cmd_wstatus = 0;
	shell_config->pid_list = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_shell_config	shell_config;

	(void)ac;
	(void)av;
	load_shell_config(&shell_config, env);
	set_signal();
	show_shell_logo();
	shell_loop(&shell_config);
	delete_environ(shell_config.envp);
	free(shell_config.envp);
	return (EXIT_SUCCESS);
}
