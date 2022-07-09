/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:30:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 16:48:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ss;

	ss = s;
	while (*s)
		s++;
	while (*s != c)
	{
		if (*s == *ss)
			return (0);
		s--;
	}
	return ((char *)s);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[10] = "abcdeabcde";

	printf("--str--\n%s", str);
	printf("\n--strrchr('f')--\n%s%c\n%s%s", \
		"located character : ", *strrchr(str, 'c'), \
		"string : ", strrchr(str, 'c'));
	printf("\n--strrchr('k')--\n%s", strrchr(str, 'k'));
	printf("\n--ft_strrchr('f')--\n%s%c\n%s%s", \
		"located character : ", *ft_strrchr(str, 'c'), \
		"string : ", ft_strrchr(str, 'c'));
	printf("\n--ft_strrchr('k')--\n%s", ft_strrchr(str, 'k'));
}
*/