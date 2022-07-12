/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:15:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/12 14:08:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[10] = { "abcdeabcde" };

	printf("--str--\n%s", str);
	printf("\n--strchr('f')--\n%s%c\n%s%s", \
		"located character : ", *strchr(str, 'c'), \
		"string : ", strchr(str, 'c'));
	printf("\n--strchr('k')--\n%s", strchr(str, 'k'));
	printf("\n--ft_strchr('f')--\n%s%c\n%s%s", \
		"located character : ", *ft_strchr(str, 'c'), \
		"string : ", ft_strchr(str, 'c'));
	printf("\n--ft_strchr('k')--\n%s", ft_strchr(str, 'k'));
}
*/