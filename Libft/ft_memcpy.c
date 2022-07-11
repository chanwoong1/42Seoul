/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:33:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 12:14:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		*((unsigned char *)dst++) = *((unsigned char *)src++);
	return (dst);
}

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
	return 0;
}
*/