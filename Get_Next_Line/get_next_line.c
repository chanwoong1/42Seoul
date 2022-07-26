/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:05:56 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/27 07:09:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *s1, int size)
{
	char	*cp;
	int		i;

	cp = (char *)malloc(sizeof(char) * (size + 1));
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < size)
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	*read_line(char **backup, char *buf)
{
	char	*ret;
	char	*new_backup;
	int		n_b_s;

	ret = NULL;
	if (ft_strchr(*backup) == -1)
	{
		if (*backup[0] != '\0')
			ret = ft_strdup(*backup, ft_strlen(*backup));
		free(*backup);
		*backup = NULL;
	}
	else
	{
		ret = ft_strdup(*backup, (ft_strchr(*backup + 1)));
		n_b_s = ft_strlen((*backup + ft_strchr(*backup) + 1));
		new_backup = ft_strdup((*backup + ft_strchr(*backup) + 1), n_b_s);
		free(*backup);
		*backup = new_backup;
	}
	free(buf);
	return (ret);
}

char	*read_buf(int fd, char **backup, char *buf)
{
	ssize_t	read_size;
	char	*new_backup;

	buf[BUFFER_SIZE] = '\0';
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		new_backup = ft_strjoin(*backup, buf);
		free(*backup);
		*backup = new_backup;
		if (ft_strchr(*backup) != -1)
			return (read_line(backup, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(backup, buf));
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, " ", 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	if (backup != NULL && ft_strchr(backup) != -1)
		return (read_line(&backup, buf));
	if (backup == NULL)
	{
		backup = (char *)malloc(sizeof(char));
		if (!backup)
			return (NULL);
		backup[0] = 0;
	}
	return (read_buf(fd, &backup, buf));
}
