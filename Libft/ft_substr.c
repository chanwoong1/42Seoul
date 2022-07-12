/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:43:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 20:59:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	slen;
	unsigned int	range;

	slen = 0;
	while (s[slen])
		slen++;
	if (slen - 1 < start)
		return (0);
	if (slen - 1 < start + len)
		range = slen - start;
	else
		range = len;
	sub = (char *)malloc(sizeof(char) * range);
	slen = 0;
	while (slen < range)
	{
		sub[slen] = s[start + slen];
		slen++;
	}
	return (sub);
}

/*
#include <stdio.h>
int main(void)
{
	char *s = "Hello, World!";

	printf("\n--------------------\n");
	printf("%s%s\n", "s : ", s);
	printf("%s%s\n", "ft_substr(s, 2, 7) : ", ft_substr(s, 2, 7));
	printf("%s%s\n", "ft_substr(s, 7, 7) : ", ft_substr(s, 7, 7));
	printf("%s%s\n", "ft_substr(s, 14, 7) : ", ft_substr(s, 14, 7));
	return 0;
}
*/