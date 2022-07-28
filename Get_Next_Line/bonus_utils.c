/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:10:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 02:13:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*copy;
	size_t	s1_size;
	size_t	s2_size;
	size_t	size;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	size = s1_size + s2_size;
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
	{
		free(s1);
		s1 = 0;
		return (0);
	}
	while (*s1)
		*copy++ = *s1++;
	s1 -= s1_size;
	free(s1);
	while (*s2)
		*copy++ = *s2++;
	*copy = '\0';
	copy -= (size);
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	idx;

	if (!len)
		return (0);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	idx = -1;
	while (++idx < len)
		copy[idx] = s[start++];
	copy[idx] = '\0';
	return (copy);
}

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*copy;

	src_len = ft_strlen(src);
	copy = malloc(sizeof(char) * (src_len + 1));
	if (!copy)
		return (0);
	while (*src)
		*copy++ = *src++;
	*copy = '\0';
	copy -= src_len;
	return (copy);
}