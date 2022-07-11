/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:49:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 12:15:59 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	n;
	size_t	src_len;

	n = dstsize;
	src_len = 0;
	dst_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dst[dst_len] != '\0')
		dst_len++;
	n = dstsize - dst_len;
	if (n == 0)
		return (dst_len + src_len);
	while (*src != '\0')
	{
		if (n != 1)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char dst[5] = {1, 2, 3};
	int i;

	printf("---src---\n");
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", src[i], "]");
	printf("\n---strlcat---");
	printf("\n%lu\n", strlcat(dst, src, 5));
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", dst[i], "]");
	char dst1[5] = {1, 2, 3};
	printf("\n---ft_strlcat---");
	printf("\n%lu\n", ft_strlcat(dst1, src, 5));
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", dst[i], "]");
}
*/