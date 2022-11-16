/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:54:18 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 08:54:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

int	gnl_strchr(char *s)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	while (s[len])
		len++;
	while (idx < len)
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		idx;
	int		size_s1;
	int		size_s2;
	char	*join;

	size_s1 = gnl_strlen(s1);
	size_s2 = gnl_strlen(s2);
	join = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!join)
		return (NULL);
	idx = 0;
	while (*s1)
		join[idx++] = *s1++;
	while (*s2)
		join[idx++] = *s2++;
	join[idx] = '\0';
	return (join);
}