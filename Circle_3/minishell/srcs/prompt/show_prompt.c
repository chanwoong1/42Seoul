/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:52:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/12 12:53:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_shell(void)
{
	ft_freestrarr(g_envv);
	write(1, "\n", 1);
	exit(0);
}

char	*parse_home_path(char *path, int reverse_parse)
{
	char	*home_path;
	char	*new;

	if (!path)
		return (NULL);
	home_path = get_env_var("HOME");
	if (!ft_strstartswith(path, reverse_parse ? "~" : home_path))
		return (ft_strdup(path));
	if (reverse_parse)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (new);
}

void	display_prompt_msg(void)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*parsed_cwd;

	cwd = getcwd(buff, 4096);
	parsed_cwd = parse_home_path(cwd, 0);
	ft_putstr(parsed_cwd);
	free(parsed_cwd);
	ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
}