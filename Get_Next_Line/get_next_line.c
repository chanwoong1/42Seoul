/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:25:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/25 18:25:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_buf(int fd, char *tmp)
{
	ssize_t	read_size;
	char	*buf;
	char	*ret;

	ret = 0;
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (FAIL);
		if (ft_find(buf))
		{
			ret = (char *)malloc(sizeof(char) * (ft_find(buf) + 2));
			if (!ret)
				return (FAIL);
			ft_strlcpy(ret, buf, (ft_find(buf) + 2));
			ft_strchr(buf, '\n');

		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0)
		return (FAIL);
	line = read_buf(fd, tmp);
	return (line);
}
