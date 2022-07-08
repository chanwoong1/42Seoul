/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:15:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/08 20:44:16 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
    int i;

    i = 0;
    while (i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (i);     
}

#include <stdio.h>
#include <string.h>
int main(void)
{
    char src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char dst[10];
    int i;

    printf("---src---\n");
    for (i = 0; i < 10; i++)
        printf("%s%d%s", "[", src[i], "]");
    strlcpy(dst, src, 5);
    printf("\n---strlcpy---\n");
    for (i = 0; i < 10; i++)
        printf("%s%d%s", "[", dst[i], "]");
    char dst1[10];
    ft_strlcpy(dst1, src, 5);
    printf("\n---ft_strlcpy---\n");
    for (i = 0; i < 10; i++)
        printf("%s%d%s", "[", dst[i], "]");
}