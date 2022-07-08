/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:33:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/08 17:12:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
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
	int dest[3];

	memcpy(dest, src, sizeof(int) * 3); 
	for (int i = 0; i < 6; ++i)
	{
		printf("%d", src[i]);
	}
	printf("\n");
	for (int i = 0; i < 6; ++i)
	{
		printf("%d", dest[i]);
	}
	return 0;
}
*/