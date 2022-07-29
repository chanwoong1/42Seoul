/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:56:57 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 11:03:58 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

ssize_t	ft_find_line(char *buff)
{
	ssize_t	i;

	i = 0;
	if (buff == NULL)
		return (-1);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_list	*ft_fd_find(int fd, t_list *node)
{
	while (node != NULL)
	{
		if (node -> fd_index == fd)
			return (node);
		node = node -> next;
	}
	return (NULL);
}

void	ft_clear_buf(t_list *node, size_t i_lf, size_t len)
{
	char	*temp;

	if ((node -> buff)[i_lf + 1] != '\0')
		temp = ft_strndup((node -> buff) + (i_lf + 1), len - i_lf);
	else
		temp = NULL;
	free(node -> buff);
	node -> buff = temp;
}

char	*ft_get_line(int fd, t_list *node)
{
	char	buf[BUFFER_SIZE];
	ssize_t	len;

	if (node -> i_eof == 0)
	{
		free(node -> buff);
		return (NULL);
	}
	if (ft_find_line(node -> buff) != -1)
		ft_clear_buf(node, ft_find_line(node -> buff), ft_strlen(node -> buff));
	while (ft_find_line(node -> buff) == -1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
			node -> buff = ft_strjoin(node -> buff, buf, len);
		if (len < BUFFER_SIZE && ft_find_line(node -> buff) == -1)
		{
			node -> i_eof = 0;
			return (node -> buff);
		}
	}
	return (node -> buff);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;

	if (!(ft_fd_find(fd, list)))
		if (!(ft_new_node(fd, &list)))
			return (NULL);
	str = ft_get_line(fd, ft_fd_find(fd, list));
	if (str == NULL)
	{
		ft_node_clear(&list, fd);
		return (NULL);
	}
	else if (ft_find_line(str) != -1)
		return (ft_strndup(str, ft_find_line(str) + 1));
	else
		return (ft_strndup(str, ft_strlen(str)));
}

// #include "get_next_line_bonus.h"
// #include <stdio.h>

// static void	free_buff(t_list **head, int fd)
// {
// 	t_list	*temp;
// 	t_list	*free_list;

// 	// printf("fd : %d\n", fd);
// 	temp = *head;
// 	if (temp->fd == fd)
// 	{
// 		*head = temp->next;
// 		free(temp->backup);
// 		// free(temp);
// 		return ;
// 	}
// 	while (temp->next->fd != fd)
// 		temp = temp->next;
// 	free_list = temp->next;
// 	temp->next = free_list->next;
// 	free(free_list->backup);
// 	// free(free_list);
// }

// static char	*ft_strdup(const char *s1, int size)
// {
// 	char	*cp;
// 	int		i;

// 	cp = (char *)malloc(sizeof(char) * (size + 1));
// 	if (cp == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] && i < size)
// 	{
// 		cp[i] = s1[i];
// 		i++;
// 	}
// 	cp[i] = '\0';
// 	return (cp);
// }

// static char	*read_line(t_list **fd_list, char *buf)
// {
// 	char	*ret;
// 	char	*new_backup;
// 	int		n_b_s;

// 	ret = NULL;
// 	if (ft_strchr((*fd_list)->backup) == -1)
// 	{
// 		if ((*fd_list)->backup[0] != '\0')
// 			ret = ft_strdup((*fd_list)->backup, ft_strlen((*fd_list)->backup));
// 		free((*fd_list)->backup);
// 		(*fd_list)->backup = NULL;
// 		free_buff(fd_list, (*fd_list)->fd);
// 	}
// 	else
// 	{
// 		ret = ft_strdup((*fd_list)->backup, ft_strchr((*fd_list)->backup) + 1);
// 		n_b_s = ft_strlen((*fd_list)->backup + ft_strchr((*fd_list)->backup) + 1);
// 		new_backup = ft_strdup(((*fd_list)->backup + ft_strchr((*fd_list)->backup) + 1), n_b_s);
// 		free((*fd_list)->backup);
// 		(*fd_list)->backup = new_backup;
// 	}
// 	free(buf);
// 	return (ret);
// }

// static char	*read_buf(int fd, t_list **fd_list, char *buf)
// {
// 	ssize_t	read_size;
// 	char	*new_backup;

// 	buf[BUFFER_SIZE] = '\0';
// 	read_size = read(fd, buf, BUFFER_SIZE);
// 	while (read_size > 0)
// 	{
// 		buf[read_size] = '\0';
// 		new_backup = ft_strjoin((*fd_list)->backup, buf);
// 		(*fd_list)->backup = new_backup;
// 		if (ft_strchr((*fd_list)->backup) != -1)
// 			return (read_line(fd_list, buf));
// 		read_size = read(fd, buf, BUFFER_SIZE);
// 	}
// 	return (read_line(fd_list, buf));
// }

// static t_list	*ft_lstnew(int fd)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (0);
// 	if (!(new->backup = malloc(1)))
// 		return (0);
// 	new->next = NULL;
// 	new->backup[0] = '\0';
// 	new->fd = fd;
// 	return (new);
// }

// static t_list	*find_buff(t_list *confirm, int fd)
// {
// 	while (confirm)
// 	{
// 		if (confirm->fd == fd)
// 			break ;
// 		if (confirm->next == NULL)
// 			if (!(confirm->next = ft_lstnew(fd)))
// 				return (0);
// 		confirm = confirm->next;
// 	}
// 	return (confirm);
// }

// char	*get_next_line(int fd)
// {
// 	static t_list	*head;
// 	t_list			*lst_buf;
// 	char			*line;
// 	char			*buf;

// 	if (BUFFER_SIZE <= 0 || (!head && !(head = ft_lstnew(fd))) ||
// 		!(lst_buf = find_buff(head, fd)))
// 		return (NULL);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (NULL);
// 	if (lst_buf->backup != NULL && ft_strchr(lst_buf->backup) != -1)
// 	{
// 		line = read_line(&lst_buf, buf);
// 		return (line);
// 	}
// 	if (lst_buf->backup == NULL)
// 	{
// 		lst_buf->backup = (char *)malloc(sizeof(char));
// 		if (!lst_buf->backup)
// 			return (NULL);
// 		lst_buf->backup[0] = '\0';
// 	}
// 	line = read_buf(fd, &lst_buf, buf);
// 	return (line);
// }
