/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:58:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/26 14:16:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

size_t	ft_len_or_find(char *str, int flag)
{
	int	len;
	int	idx;

	len = 0;
	while (str[len])
		len++;
	idx = 0;
	if (flag == 1)
	{
		while (str[idx])
		{
			if (str[idx] == '\n')
				return (idx);
			idx++;
		}
		return (-1);
	}
	else
		return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (dstsize < 1)
		return (j);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

void	*ft_calloc(size_t size)
{
	unsigned char	*ret;

	ret = (void *)malloc(size);
	if (!ret)
		return (0);
	while (size--)
		ret[size] = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	size_t	s1_size;
	size_t	s2_size;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_len_or_find((char *)s1, 0);
	s2_size = ft_len_or_find((char *)s2, 0);
	size = s1_size + s2_size;
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	copy[0] = '\0';
	ft_strcat(copy, (char *)s1);
	ft_strcat(copy + s1_size, (char *)s2);
	free((char *)s1);
	return (copy);
}