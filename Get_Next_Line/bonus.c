/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:10:20 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 02:29:35 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*read_line(int fd, char **buffer)
{
	char		temp[BUFFER_SIZE + 1];
	ssize_t		read_size;

	temp[0] = 0;
	while (!ft_strchr(temp, '\n'))
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
		{
			if (*buffer)
				free(*buffer);
			return (0);
		}
		temp[read_size] = '\0';
		if (!*buffer)
			*buffer = ft_strdup(temp);
		else
			*buffer = ft_strjoin(*buffer, temp);
		if (!*buffer)
			return (0);
	}
	return (*buffer);
}

char	*extract_line(char **buffer)
{
	int		len;
	char	*line;

	len = 0;
	while (**buffer != '\n' && **buffer)
	{
		++len;
		++*buffer;
	}
	if (**buffer == '\n')
		line = ft_substr(*buffer - len, 0, len + 1);
	else
		line = ft_strdup(*buffer - len);
	return (line);
}

char	*change_next_line(char **buffer)
{
	char	*next_line;
	char	*init_pos;
	int		len;

	init_pos = *buffer;
	while (**buffer != '\n' && **buffer)
		++*buffer;
	len = *buffer - init_pos;
	if (!(**buffer))
	{
		free(*buffer - len);
		return (0);
	}
	*buffer -= len;
	next_line = ft_substr(buffer, len + 1, ft_strlen(buffer + len + 1));
	free(buffer);
	return (next_line);
}

static t_list	*ft_lstnew(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	if (!(new->backup = malloc(1)))
		return (0);
	new->next = NULL;
	new->backup[0] = '\0';
	new->fd = fd;
	return (new);
}

static t_list	*find_buff(t_list *confirm, int fd)
{
	while (confirm)
	{
		if (confirm->fd == fd)
			break ;
		if (confirm->next == NULL)
			if (!(confirm->next = ft_lstnew(fd)))
				return (0);
		confirm = confirm->next;
	}
	return (confirm);
}

char	*get_next_line(int fd)
{
	static t_list   *head;
    t_list          *fd_list;
	char			*line;

    if (BUFFER_SIZE <= 0 || (!head && !(head = ft_lstnew(fd))) ||
		!(fd_list = find_buff(head, fd)) || fd < 0)
		return (0);
	fd_list->backup = read_line(fd, &fd_list->backup);
	if (!(fd_list->backup))
		return (0);
	line = extract_line(&fd_list->backup);
	fd_list->backup = change_next_line(&fd_list->backup);
	return (line);
}