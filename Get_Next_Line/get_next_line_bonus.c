/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:56:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/28 21:44:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static void	free_buff(t_list **head, int fd);

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

static char	*read_line(t_list **fd_list, char *buf)
{
	char	*ret;
	char	*new_backup;
	int		n_b_s;

	ret = NULL;
	if (ft_strchr((*fd_list)->backup) == -1)
	{
		if ((*fd_list)->backup[0] != '\0')
			ret = ft_strdup((*fd_list)->backup, ft_strlen((*fd_list)->backup));
		free((*fd_list)->backup);
		(*fd_list)->backup = NULL;
	}
	else
	{
		ret = ft_strdup((*fd_list)->backup, ft_strchr((*fd_list)->backup) + 1);
		n_b_s = ft_strlen((*fd_list)->backup + ft_strchr((*fd_list)->backup) + 1);
		new_backup = ft_strdup(((*fd_list)->backup + ft_strchr((*fd_list)->backup) + 1), n_b_s);
		free((*fd_list)->backup);
		(*fd_list)->backup = new_backup;
	}
	free(buf);
	free_buff(fd_list, (*fd_list)->fd);
	return (ret);
}

static char	*read_buf(int fd, t_list **fd_list, char *buf)
{
	ssize_t	read_size;
	char	*new_backup;

	buf[BUFFER_SIZE] = '\0';
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		new_backup = ft_strjoin((*fd_list)->backup, buf);
		free((*fd_list)->backup);
		(*fd_list)->backup = new_backup;
		if (ft_strchr((*fd_list)->backup) != -1)
			return (read_line(fd_list, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(fd_list, buf));
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

static void	free_buff(t_list **head, int fd)
{
	t_list	*tmp;
	t_list	*free_list;

	tmp = *head;
	if (tmp->fd == fd)
	{
		*head = tmp->next;
		free(tmp->backup);
		free(tmp);
		return ;
	}
	while (tmp->next->fd != fd)
		tmp = tmp->next;
	free_list = tmp->next;
	tmp->next = free_list->next;
	free(free_list->backup);
	free(free_list);
}

char	*get_next_line(int fd)
{
	static t_list		*fd_list;
	t_list				*confirm;
	char				*buf;

	if (BUFFER_SIZE <= 0 || (!fd_list && !(fd_list = ft_lstnew(fd))) ||
		!(confirm = find_buff(fd_list, fd)))
		return (NULL);
	fd_list = (t_list *)malloc(sizeof(t_list));
	if (!fd_list)
		return (NULL);
	confirm = ft_lstnew(fd);
	if (!confirm)
		return (NULL);
	if (fd_list->fd == 0)
		fd_list->fd = fd;
	while (fd_list != NULL)
	{
		if (fd_list->fd == confirm->fd)
			break;
		fd_list = fd_list->next;
	}
	if (fd_list->fd != confirm->fd && fd_list->next == NULL)
		fd_list->next = confirm;
	free(confirm);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	if (fd_list->backup != NULL && ft_strchr(fd_list->backup) != -1)
		return (read_line(&fd_list, buf));
	if (fd_list->backup == NULL)
	{
		fd_list->backup = (char *)malloc(sizeof(char));
		if (!fd_list->backup)
			return (NULL);
		fd_list->backup[0] = '\0';
	}
	return (read_buf(fd, &fd_list, buf));
}

int		get_next_line(int fd)
{
	static t_list	*head;
	t_list			*lst_buf;
	ssize_t			size;
	int				found;

	if (BUFFER_SIZE <= 0 || (!head && !(head = new_buff(fd))) ||
		!(lst_buf = find_buff(head, fd)))
		return (-1);
	*line = 0;
	while (!(found = find_new_line(line, lst_buf)) &&
		((size = read(fd, lst_buf->temp_buff, BUFFER_SIZE)) > 0))
	{
		lst_buf->temp_buff[size] = '\0';
		lst_buf->buff = gnl_strjoin(&(lst_buf->buff), lst_buf->temp_buff);
	}
	if (found)
		return (found);
	if (size < 0)
		return (-1);
	*line = malloc(gnl_strlen(lst_buf->buff) + 1);
	gnl_strlcpy(*line, lst_buf->buff, gnl_strlen(lst_buf->buff) + 1);
	free_buff(&head, fd);
	return (0);
}

https://github.com/meong99/42_seoul/blob/master/02_get_next_line/get_next_line.c

