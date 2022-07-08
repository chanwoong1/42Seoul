/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:49:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/08 17:09:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    while (len--)
        *((unsigned char *)dst++) = *((unsigned char *)src++);
    return (dst);
}

#include <string.h>
#include <stdio.h>
int main(void)
{
    int src[5] = {1, 2, 3, 4, 5};
    int dst[5];
    int i;
    
    printf("==설정 전==\n");
    for(i = 0; i < 5; i++)
        printf("%s%d%s", "[", dst[i], "]");
    memmove(dst, src, sizeof(int) * 3);
    printf("\n==memmove 설정 후==\n");
    for(i = 0; i < 5; i++)
        printf("%s%d%s", "[", dst[i], "]");
    int dst1[5];
    ft_memmove(dst1, src, sizeof(int) * 3);
    printf("\n==ft_memmove 설정 후==\n");
    for(i = 0; i < 5; i++)
        printf("%s%d%s", "[", dst1[i], "]");
}