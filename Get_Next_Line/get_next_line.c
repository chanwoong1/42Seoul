/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:25:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/26 17:48:16 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_buf(int fd, char *tmp)
{
	ssize_t	read_size;
	char	*buf;

	buf = (char *)ft_calloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (FAIL);
	read_size = read(fd, buf, BUFFER_SIZE);
	while ((int)ft_len_or_find(buf, 1) == -1)
	{
		tmp = ft_strjoin(tmp, buf);
		free(buf);
		buf = (char *)ft_calloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (FAIL);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
	}
	return (buf);
}

char	*read_line(char *buf, char *tmp)
{
	char	*ret;
	int		buf_size;

	ret = 0;
	if ((buf_size = (int)ft_len_or_find(buf, 1)) >= 0)
	{
		ret = (char *)ft_calloc(sizeof(char) * ((int)ft_len_or_find(buf, 1) + 1));
		if (!ret)
			return (0);
		ft_strlcpy(ret, buf, (int)ft_len_or_find(buf, 1) + 1);
		ret = ft_strjoin(tmp, ret);
		free(tmp);
		tmp = (char *)ft_calloc(sizeof(char) *(BUFFER_SIZE - (int)ft_len_or_find(buf, 1) + 1));
		if (!tmp)
			return (FAIL);
		ft_strlcpy(tmp, buf + (int)ft_len_or_find(buf, 1), BUFFER_SIZE - (int)ft_len_or_find(buf, 1));
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	char		*buf;

	buf = 0;
	if (fd < 0)
		return (FAIL);
	if (tmp == 0)
	{
		tmp = (char *)ft_calloc(1);
		if (!tmp)
			return (FAIL);
	}
	if ((int)ft_len_or_find(tmp, 1) == -1)
		buf = read_buf(fd, tmp);
	line = read_line(buf, tmp);
	free(buf);
	return (line);
}

// 	if ((buf_size = (int)ft_len_or_find(buf, 1)) >= 0)
// 	{
// 		ret = (char *)ft_calloc(sizeof(char) * ((int)ft_len_or_find(buf, 1) + 1));
// 		if (!ret)
// 			return (0);
// 		ft_strlcpy(ret, buf, (int)ft_len_or_find(buf, 1) + 1);
// 		ret = ft_strjoin(tmp, ret);
// 		free(tmp);
// 		tmp = (char *)ft_calloc(sizeof(char) *(BUFFER_SIZE - (int)ft_len_or_find(buf, 1) + 1));
// 		if (!tmp)
// 			return (FAIL);
// 		ft_strlcpy(tmp, buf + (int)ft_len_or_find(buf, 1), BUFFER_SIZE - (int)ft_len_or_find(buf, 1));
// 	}
// 	return (ret);
// }
