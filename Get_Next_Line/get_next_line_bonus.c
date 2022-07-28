/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:56:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/28 15:03:41 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static char	*ft_strdup(const char *s1, int size)
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

static char	*read_line(t_list *fd_list, char *buf)
{
	char	*ret;
	char	*new_backup;
	int		n_b_s;

	ret = NULL;
	if (ft_strchr(fd_list->backup) == -1)
	{
		if (fd_list->backup[0] != '\0')
			ret = ft_strdup(fd_list->backup, ft_strlen(fd_list->backup));
		free(fd_list->backup);
		fd_list->backup = NULL;
	}
	else
	{
		ret = ft_strdup(fd_list->backup, ft_strchr(fd_list->backup) + 1);
		n_b_s = ft_strlen(fd_list->backup + ft_strchr(fd_list->backup) + 1);
		new_backup = ft_strdup((fd_list->backup + ft_strchr(fd_list->backup) + 1), n_b_s);
		free(fd_list->backup);
		fd_list->backup = new_backup;
	}
	free(buf);
	return (ret);
}

static char	*read_buf(int fd, t_list *fd_list, char *buf)
{
	ssize_t	read_size;
	char	*new_backup;

	buf[BUFFER_SIZE] = '\0';
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		new_backup = ft_strjoin(fd_list->backup, buf);
		free(fd_list->backup);
		fd_list->backup = new_backup;
		if (ft_strchr(fd_list->backup) != -1)
			return (read_line(fd_list, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(fd_list, buf));
}

t_list	*ft_lstnew(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = 0;
	new->content = content;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_list		*fd_list;
	char				*buf;

	printf("----gnl start----\n");
	printf("fd : %d\n", fd);
	fd_list = (t_list *)malloc(sizeof(t_list));
	if (!fd_list)
		return (0);
	if (fd_list->fd == 0)
		fd_list->fd = fd;
	while (fd_list != NULL)
	{
		printf("in while roof\n");
		if (fd_list->fd == fd)
			break;
		fd_list = fd_list->next;
	}
	printf("while roof end\n");
	if (!fd_list)
		fd_list->fd = fd;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	if (fd_list->backup != NULL && ft_strchr(fd_list->backup) != -1)
		return (read_line(fd_list, buf));
	if (fd_list->backup == NULL)
	{
		fd_list->backup = (char *)malloc(sizeof(char));
		if (!fd_list->backup)
			return (NULL);
		fd_list->backup[0] = '\0';
	}
	return (read_buf(fd, fd_list, buf));
}
