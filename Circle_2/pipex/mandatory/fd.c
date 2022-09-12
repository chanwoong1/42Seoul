/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:56:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/12 15:41:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_fd(t_env *info, int argc, char **argv)
{
	info->i_fd = open(argv[1], O_RDONLY);
	if (info->i_fd < 0)
		perror(ERR_INFILE);
	info->o_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->o_fd < 0)
		exit_perror(ERR_OUTFILE, 1);
}

void	parent_free(t_env *info)
{
	close(info->i_fd);
	close(info->o_fd);
}
