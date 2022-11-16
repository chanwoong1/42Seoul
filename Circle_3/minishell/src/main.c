/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:33:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 09:44:13 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
** Parses a string to convert variables to their value then returns the parsed
** string
**
** @param		str		The input string to parse
** @param		pos		The position from which to start in the string
*/

static char		*parse_env_var(char *str, int pos)
{
	char	*value;
	char	*key;
	char	c;

	key = ft_strnew(1);
	while (str[pos] && !IS_SPACE(str[pos]))
	{
		c = str[pos];
		key = ft_strjoinchcl(key, c);
		pos++;
	}
	if (!(value = get_env_var(key)))
	{
		free(key);
		return (NULL);
	}
	free(key);
	return (value);
}

/*
** Parses the input by changing $VAR_NAME to the value of VAR_NAME in the
** environment variable or by nothing if it doesn't exist and by changing ~
** to the value of the user's home path then returns the parsed string
**
** @param		input		The input string
** @return		The parsed string
*/

static char		*parse_input(char *input)
{
	int		i;
	char	*new;

	i = -1;
	new = ft_strnew(1);
	while (input[++i])
	{
		if (input[i] == '$' && input[i + 1])
		{
			new = ft_strjoincl(new, parse_env_var(input, i + 1), 0);
			while (input[i + 1] && !IS_SPACE(input[i + 1]) &&
				input[i + 1] != '$')
				i++;
		}
		else if (((i != 0 && IS_SPACE(input[i - 1])) || i == 0) &&
			input[i] == '~')
		{
			new = ft_strjoincl(new, parse_home_path(input + i, 1), 1);
			i += ft_strlen(input + i) - 1;
		}
		else
			new = ft_strjoinchcl(new, input[i]);
	}
	free(input);
	return (new);
}

/*
** Displays a prompt on the screen and fills the input character by character
** then adds it to the referenced variable (input) after parsing the whole
** input if necessary
** TODO: Not the most efficient way, will improve it later
**
** @param	input	The address of the variable to fill with the parsed input
** @return	N/A
*/

static void		get_input(char **input, t_shell *shell)
{
	int		ret;
	char	buf;
	int		i;
	int		count;

	// *input = ft_strnew(1);
	// count = 1;
	// i = 0;
	// while ((ret = read(0, &buf, 1)) && buf != '\n')
	// {
	// 	*(*input + i++) = buf;
	// 	*input = ft_realloc(*input, count, count + 1);
	// 	count++;
	// }
	// *(*input + i) = '\0';
	shell->idx++;
	input = readline("minishell> ");
	if (!input)
	{
		free(*input);
		exit_shell();
	}
	save_history(shell, input);
	if ((ft_strchr(*input, '$') != NULL) || (ft_strchr(*input, '~') != NULL))
		*input = parse_input(*input);
}

/*
** Takes care of multiple commands in the input
**
** @param		commands	The list of commands to execute
** @return		-1 if there was an interruption from one of the commands
**				or 0/1 if not
*/

int				exec_commands(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = -1;
	ret = 0;
	while (commands[++i])
	{
		command = ft_strsplitall(commands[i]);
		ret = exec_command(command);
		ft_freestrarr(command);
		if (ret == -1)
			break ;
	}
	return (ret);
}

/*
** Initializes minishell
**
** @param	ac		argument counts
** @param	av		argument variables
** @param	envv	environment variables
** @return	0 on completion
*/

int				main(int ac, char **av, char **envp)
{
	char	*input;
	int		ret;
	char	**commands;
	t_shell shell;

	// init_envv(ac, av, envp, &shell);
	init_shell(ac, av, envp, &shell);
	while (1)
	{
		display_prompt_msg();
		signal(SIGINT, signal_handler);
		get_input(&input, &shell);
		if (ft_isemptystr(input, 1))
		{
			free(input);
			continue ;
		}
		commands = ft_strsplit(input, ';');
		free(input);
		ret = exec_commands(commands);
		ft_freestrarr(commands);
		if (ret == -1)
			break ;
	}
	ft_freestrarr(g_envp);
	return (0);
}
