/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:43:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/10/02 18:01:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_i_fd(t_parse **cmd_parse, char **cmd_split)
{
	if (!ft_strncmp(cmd_split[0], "<<", 2))
	{
		(*cmd_parse)->here_doc = 1;
		here_doc(cmd_split[1]);
		(*cmd_parse)->i_fd = open("./heredoc/heredoc_tmp", O_RDONLY);
		if ((*cmd_parse)->i_fd < 0)
		{
			unlink("./heredoc/heredoc_tmp");
			error_exit("fail with here_doc create, try one more time.", 1);
		}
	}
	else
	{
		(*cmd_parse)->i_fd = open(cmd_split[0], O_RDONLY);
		if ((*cmd_parse)->i_fd < 0)
			(*cmd_parse)->i_fd = 0;
	}
}

void	get_o_fd(t_parse **cmd_parse, char **cmd_split)
{
	int	i;

	i = 0;
	while (cmd_split[i])
		i++;
	if (!ft_strncmp(cmd_split[i - 2], ">>", 2))
		(*cmd_parse)->o_fd = open(cmd_split[i - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else if (!ft_strncmp(cmd_split[i - 2], ">", 1))
		(*cmd_parse)->o_fd = open(cmd_split[i - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	else
		(*cmd_parse)->o_fd = 1;
	if ((*cmd_parse)->o_fd < 0)
		error_exit("fail with here_doc open, try one more time.", 1);
}
