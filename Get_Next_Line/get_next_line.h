/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:50:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/14 16:21:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# define BUFFER_SIZE	42
# define FAIL			-1
# define SUCCESS		0

typedef struct s_info
{
	int			fd;
	int			size;
	int			len;
	char		buf[4096];
	char		**buf_split;
}				t_info;

char    *get_next_line(int fd);

#endif

