/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:50:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 15:00:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((int)(s1[i] - s2[i]));
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