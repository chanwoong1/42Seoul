/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:50:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/12 14:30:40 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] && i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (us1[i] == '\0' && i < n)
		return (us1[i] - us2[i]);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char s2[10] = {1, 2, 3, 4, 5, 6, 7, 9, 8, 0};
	int i;

	printf("---s1---\n");
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", s1[i], "]");
	printf("\n---s2---\n");
	for (i = 0; i < 10; i++)
		printf("%s%d%s", "[", s2[i], "]");
	printf("\n---strncmp---");
	printf("\n%d\n", strncmp(s1, s2, 10));
	printf("\n---ft_strncmp---");
	printf("\n%d\n", ft_strncmp(s1, s2, 10));
}
*/