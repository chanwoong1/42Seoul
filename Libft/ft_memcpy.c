/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:33:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/12 15:05:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

// void	*ft_memcpy(void *dest, const void *source, size_t num)
// {
// 	char		*dest_point;
// 	const char	*source_point;

// 	if (dest == NULL && source == NULL)
// 		return (NULL);
// 	dest_point = dest;
// 	source_point = source;
// 	while (num > 0)
// 	{
// 		dest_point[num - 1] = source_point[num - 1];
// 		num--;
// 	}
// 	return (dest);
// }

/*
#include<string.h>
#include<stdio.h>
int main(void)
{
	int src[] = {1,2,3,4, 5, 6};
	int dst[3];

	printf("\n--------------------\n");
	printf("%s\n", "src : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", src[i]);
	printf("\n%s", "dst : ");
	for (int i = 0; i < 3; ++i)
		printf("%d", dst[i]);
	memcpy(dst, src, sizeof(int) * 3);
	printf("\n%s", "memcpy(dst) : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", dst[i]);
	int dst1[3];
	printf("\n--------------------\n");
	printf("%s\n", "src : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", src[i]);
	printf("\n%s", "dst : ");
	for (int i = 0; i < 3; ++i)
		printf("%d", dst1[i]);
	ft_memcpy(dst1, src, sizeof(int) * 3);
	printf("\n%s", "ft_memcpy(dst) : ");
	for (int i = 0; i < 6; ++i)
		printf("%d", dst1[i]);

	printf("\n\n\n%s\n", ft_memcpy(((void *)0), ((void *)0), 3));
	return 0;
}
*/