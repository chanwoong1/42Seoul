/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:31:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 12:41:43 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;
	int		size;
	int		i;

	size = 0;
	while (s1[size])
		size++;
	cp = malloc(sizeof(char) * (size + 1));
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

/*
#include<string.h>
#include<stdio.h>
int main(void)
{
	char src[] = "Hello, World!";

	printf("\n--------------------\n");
	printf("%s%s\n", "src : ", src);
	printf("%s%s\n", "strdup(src) : ", strdup(src));
	printf("%s%s\n", "ft_strdup(src) : ", ft_strdup(src));
	return 0;
}
*/