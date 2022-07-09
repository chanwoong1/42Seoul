/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:15:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 16:23:09 by chanwjeo         ###   ########.fr       */
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
	char str[10] = "abcdefghij";

	printf("--str--\n%s", str);
	printf("\n--strchr('f')--\n%s", strchr(str, 'f'));
	printf("\n--strchr('k')--\n%s", strchr(str, 'k'));
	printf("\n--ft_strchr('f')--\n%s", ft_strchr(str, 'f'));
	printf("\n--ft_strchr('k')--\n%s", ft_strchr(str, 'k'));
}
*/