/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:19:30 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/02 14:20:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_cmd_parse(t_parse **cmd_parse, char **envp, char *cmd)
{
	char	**cmd_split;

	ft_memset(*cmd_parse, 0, sizeof(t_parse));
	(*cmd_parse)->envp = envp;
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		error_exit("malloc error of command, check your command.", 1);
	
	get_i_fd(cmd_parse, cmd_split);
	get_o_fd(cmd_parse, cmd_split);
	free_all_split(cmd_split);
}
