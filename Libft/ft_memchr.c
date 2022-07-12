/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:49:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/12 15:08:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc;

	uc = s;
	while (n-- != 0)
	{
		if (*uc == (unsigned char)c)
			return ((void *)uc);
		uc++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *str = "abcdeabcde";

	printf("--str--\n%s", str);
	printf("\n\n--memchr(5)--\n%s%s", \
		"string : ", memchr(str, 'c', 5));
	printf("\n\n--memchr(2)--\n%s", memchr(str, 'k', 2));
	printf("\n\n--ft_memchr(5)--\n%s%s", \
		"string : ", ft_memchr(str, 'c', 5));
	printf("\n\n--ft_memchr(2)--\n%s", ft_memchr(str, 'k', 2));
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("%s", (char *)ft_memchr(tab, -1, 7));
}
*/
