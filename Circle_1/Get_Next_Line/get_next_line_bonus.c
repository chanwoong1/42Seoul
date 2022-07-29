/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:09:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 13:07:23 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_strchr(char *s)
{
	ssize_t	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_list	*find_fd(int fd, t_list *node)
{
	while (node != NULL)
	{
		if (node->fd_index == fd)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	buf_clear(t_list *node, size_t idx, size_t len)
{
	char	*temp;

	if ((node->backup)[idx + 1] != '\0')
		temp = ft_strdup((node->backup) + (idx + 1), len - idx);
	else
		temp = NULL;
	free(node->backup);
	node->backup = temp;
}

char	*read_buf(int fd, t_list *node)
{
	char	buf[BUFFER_SIZE];
	ssize_t	len;

	if (node->f_eof == 0)
	{
		free(node->backup);
		return (NULL);
	}
	if (ft_strchr(node->backup) != -1)
		buf_clear(node, ft_strchr(node->backup), ft_strlen(node->backup));
	while (ft_strchr(node->backup) == -1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
			node->backup = ft_strjoin(node->backup, buf, len);
		if (len < BUFFER_SIZE && ft_strchr(node->backup) == -1)
		{
			node->f_eof = 0;
			return (node->backup);
		}
	}
	return (node->backup);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (!(find_fd(fd, list)))
		if (!(ft_lstnew(fd, &list)))
			return (NULL);
	line = read_buf(fd, find_fd(fd, list));
	if (line == NULL)
	{
		free_node(&list, fd);
		return (NULL);
	}
	else if (ft_strchr(line) != -1)
		return (ft_strdup(line, ft_strchr(line) + 1));
	else
		return (ft_strdup(line, ft_strlen(line)));
}
