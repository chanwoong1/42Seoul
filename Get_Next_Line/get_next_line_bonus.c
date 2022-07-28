/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:56:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 02:29:39 by chanwjeo         ###   ########.fr       */
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

	// printf("read line start\n");
	ret = NULL;
	if (ft_strchr((*fd_list)->backup) == -1)
	{
		// printf("read line 2\n");
		if ((*fd_list)->backup[0] != '\0')
			ret = ft_strdup((*fd_list)->backup, ft_strlen((*fd_list)->backup));
		free((*fd_list)->backup);
		(*fd_list)->backup = NULL;
	}
	else
	{
		// printf("read line 3\n");
		// printf("buf : %s.\n", buf);
		ret = ft_strdup((*fd_list)->backup, ft_strchr((*fd_list)->backup) + 1);
		// printf("ret : %s.\n", ret);
		n_b_s = ft_strlen((*fd_list)->backup + ft_strchr((*fd_list)->backup) + 1);
		new_backup = ft_strdup(((*fd_list)->backup + ft_strchr((*fd_list)->backup) + 1), n_b_s);
		// printf("seg?\n");
		free((*fd_list)->backup);
		(*fd_list)->backup = new_backup;
	}
	// printf("here ?? \n");
	free(buf);
	// printf("here 2 ?? \n");
	// printf("fd_list backup : %s", (*fd_list)->backup);
	// printf("fd_list fd : %d", (*fd_list)->fd);
	// free_buff(fd_list, (*fd_list)->fd);
	return (ret);
}

static char	*read_buf(int fd, t_list **fd_list, char *buf)
{
	ssize_t	read_size;
	char	*new_backup;

	// printf("read_buf start\n");
	buf[BUFFER_SIZE] = '\0';
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		// printf("read_buf 2\n");
		buf[read_size] = '\0';
		new_backup = ft_strjoin((*fd_list)->backup, buf);
		// free((*fd_list)->backup);
		(*fd_list)->backup = new_backup;
		if (ft_strchr((*fd_list)->backup) != -1)
			return (read_line(fd_list, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	// printf("read_buf 3\n");
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

	// printf("free_buf\n");
	tmp = *head;
	if (tmp->fd == fd)
	{
		*head = tmp->next;
		free(tmp->backup);
		free(tmp);
		return ;
	}
	// printf("free_buf 2\n");
	while (tmp->next->fd != fd)
		tmp = tmp->next;
	free_list = tmp->next;
	tmp->next = free_list->next;
	free(free_list->backup);
	free(free_list);
	// printf("free_buf 3\n");
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

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*lst_buf;
	char			*line;
	char			*buf;

	// printf("gnl start\n");
	if (BUFFER_SIZE <= 0 || (!head && !(head = ft_lstnew(fd))) ||
		!(lst_buf = find_buff(head, fd)))
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	// printf("gnl 2\n");
	if (lst_buf->backup != NULL && ft_strchr(lst_buf->backup) != -1)
	{
		line = read_line(&lst_buf, buf);
		free_buff(&head, fd);
		return (line);
	}
	// printf("gnl 3\n");
	if (lst_buf->backup == NULL)
	{
		lst_buf->backup = (char *)malloc(sizeof(char));
		if (!lst_buf->backup)
			return (NULL);
		lst_buf->backup[0] = '\0';
	}
	// printf("gnl 4\n");
	line = read_buf(fd, &lst_buf, buf);
	// free_buff(&head, fd);
	return (line);
}
