/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:49:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/12 12:03:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dst + (len - 1);
		s = (unsigned char *)src + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}

/*
#include <string.h>
#include <stdio.h>
int main() 
{
	char Like[10] = "ILikeYou";
	char Hate[10] = "IHateYou";
	char str[] = "12345678";

	printf("memmove before : %s\n", Like);
	ft_memmove(Like + 1, Hate + 1, 4);
	printf("memmove after : %s\n", Like);

	printf("memmove before : %s\n", str);
	ft_memmove(str+3, str +1, 3);
	printf("memmove after : %s\n", str);
    
	return 0;
}
*/