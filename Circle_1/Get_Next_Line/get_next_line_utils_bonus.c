/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:09:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 16:09:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_node(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*first_node;

	if ((*head)->fd_index == fd)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		first_node = *head;
		temp = find_fd(fd, *head);
		while ((*head)->next->fd_index != fd)
			*head = (*head)->next;
		(*head)->next = (*head)->next->next;
		free(temp);
		*head = first_node;
	}
}

char	*ft_strjoin(char *s1, char *s2, size_t size_s2)
{
	char	*join;
	size_t	size_s1;
	size_t	idx;
	size_t	k;

	idx = 0;
	k = 0;
	if (s1 == NULL)
		return (ft_strdup(s2, size_s2));
	size_s1 = ft_strlen(s1);
	join = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (join == NULL)
		return (NULL);
	while (idx < size_s1)
		join[idx++] = s1[k++];
	k = 0;
	while (idx < size_s1 + size_s2)
		join[idx++] = s2[k++];
	join[idx] = '\0';
	free(s1);
	return (join);
}

int	ft_lstnew(int fd, t_list **head)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->fd_index = fd;
	new->next = NULL;
	new->backup = NULL;
	new->f_eof = 1;
	new->next = *head;
	*head = new;
	return (1);
}

char	*ft_strdup(char *s1, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
