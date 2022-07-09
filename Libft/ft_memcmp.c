/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:19:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 17:47:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;

	uc1 = s1;
	uc2 = s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && *uc1 == *uc2 && *uc1 != '\0' && *uc2 != '\0')
	{
		uc1++;
		uc2++;
	}
	return (*uc1 - *uc2);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s1 = "abcdeabcde";
	char *s2 = "abcdefghij";

	printf("--string--\n%s%s", "s1 : ", s1);
	printf("\n%s%s", "s2 : ", s2);
	printf("\n\n--memcmp(5)--\n%s%d", \
		"compare : ", memcmp(s1, s2, 0));
	printf("\n\n--memcmp(5)--\n%s%d", \
		"compare : ", memcmp(s1, s2, 5));
	printf("\n\n--memcmp(8)--\n%s%d", \
		"compare : ", memcmp(s1, s2, 8));
	printf("\n\n--ft_memcmp(8)--\n%s%d", \
		"compare : ", ft_memcmp(s1, s2, 0));
	printf("\n\n--ft_memcmp(5)--\n%s%d", \
		"compare : ", ft_memcmp(s1, s2, 5));
	printf("\n\n--ft_memcmp(8)--\n%s%d", \
		"compare : ", ft_memcmp(s1, s2, 8));
}
*/