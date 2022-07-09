/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:07:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 20:39:28 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		while (*haystack != *needle)
		{
			haystack++;
			len--;
		}
		i = 0;
		while (haystack[i] == needle[i])
		{
			if (needle[i] == '\0')
				return ((char *)haystack);
			i++;
		}
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	
	printf("----string----\n");
	printf("%s%s\n%s%s\n\n", "largestring : ", largestring, \
		"smallstring : ", smallstring);
	printf("----strnstr----\n");
	ptr = strnstr(largestring, smallstring, 8);
	printf("%s%s\n", "strnstr(large, small, 8) : ", ptr);
	ptr = strnstr(largestring, smallstring, 2);
	printf("%s%s\n\n", "strnstr(large, small, 2) : ", ptr);
	printf("----ft_strnstr----\n");
	ptr = strnstr(largestring, smallstring, 8);
	printf("%s%s\n", "ft_strnstr(large, small, 8) : ", ptr);
	ptr = strnstr(largestring, smallstring, 2);
	printf("%s%s\n", "ft_strnstr(large, small, 2) : ", ptr);
}
*/