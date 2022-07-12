/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:49:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/12 12:20:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	if (dstsize > dst_len + 1)
	{
		while (src[i] != 0 && dst_len + i < dstsize - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = 0;
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
	return (0);
}
*/