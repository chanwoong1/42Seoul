/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:57:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 11:02:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_node_clear(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*first_node;

	if ((*head)->fd_index == fd)
	{
		temp = *head;
		*head = (*head)-> next;
		free(temp);
	}
	else
	{
		first_node = *head;
		temp = ft_fd_find(fd, *head);
		while ((*head)-> next -> fd_index != fd)
			*head = (*head)-> next;
		(*head)->next = (*head)->next -> next;
		free(temp);
		*head = first_node;
	}
}

char	*ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*temp;
	size_t	s1_len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s1 == NULL)
		return (ft_strndup(s2, s2_len));
	s1_len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (temp == NULL)
		return (NULL);
	while (i < s1_len)
		temp[i++] = s1[k++];
	k = 0;
	while (i < s1_len + s2_len)
		temp[i++] = s2[k++];
	temp[i] = '\0';
	free(s1);
	return (temp);
}

int	ft_new_node(int fd, t_list **head)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new -> fd_index = fd;
	new -> next = NULL;
	new -> buff = NULL;
	new -> i_eof = 1;
	new -> next = *head;
	*head = new;
	return (1);
}

char	*ft_strndup(char *s1, size_t n)
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

// #include "get_next_line_bonus.h"

// int	ft_strlen(const char *s)
// {
// 	int	n;

// 	n = 0;
// 	while (s[n])
// 		n++;
// 	return (n);
// }

// int	ft_strchr(char *s)
// {
// 	int	len;
// 	int	idx;

// 	len = 0;
// 	idx = 0;
// 	while (s[len])
// 		len++;
// 	while (idx < len)
// 	{
// 		if (s[idx] == '\n')
// 			return (idx);
// 		idx++;
// 	}
// 	return (-1);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		idx;
// 	int		size_s1;
// 	int		size_s2;
// 	char	*join;

// 	size_s1 = ft_strlen(s1);
// 	size_s2 = ft_strlen(s2);
// 	join = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
// 	if (!join)
// 		return (NULL);
// 	idx = 0;
// 	while (*s1)
// 		join[idx++] = *s1++;
// 	while (*s2)
// 		join[idx++] = *s2++;
// 	join[idx] = '\0';
// 	free(s1);
// 	return (join);
// }
