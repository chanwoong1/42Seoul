/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:19:30 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/02 17:58:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_quote_and_branket(t_parse **cmd_parse, t_shell *shell, char *cmd)
{
	int i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'')
			(*cmd_parse)->s_quote++;
		if (cmd[i] == '\"')
			(*cmd_parse)->d_quote++;
	}
	if ((*cmd_parse)->s_quote % 2 != 0 || (*cmd_parse)->d_quote % 2 != 0)
		error_exit("Error : not valid couple of quote", 1);
	
}

void	init_cmd_parse(t_parse **cmd_parse, t_shell *shell, char *cmd)
{
	char	**cmd_split;

	ft_memset(*cmd_parse, 0, sizeof(t_parse));
	check_quote_and_branket(cmd_parse, shell, cmd);
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		error_exit("malloc error of command, check your command.", 1);
	get_i_fd(cmd_parse, cmd_split);
	get_o_fd(cmd_parse, cmd_split);
	free_all_split(cmd_split);
}
