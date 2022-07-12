/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:07:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/12 16:29:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i + j < len)
	{
		if (haystack[i])
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				j = 0;
			if (!needle[j])
				return ((char *)(haystack + i));
		}
		else
			return (0);
		if (j == 0)
			i++;
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

	printf("----------------------------------------\n");
	char haystack[30] = "aaabcabcd";
	printf("\n\n%s", strnstr(haystack, "cd", 8));
	printf("\n\n%s", ft_strnstr(haystack, "cd", 8));
}
*/