/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:21:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 14:03:41 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	joinstr = (char *)malloc(sizeof(char) * (len + 1));
	if (joinstr == (void *)0)
		return (0);
	while (s1[i])
	{
		joinstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joinstr[i + j] = s2[j];
		j++;
	}
	joinstr[i + j] = '\0';
	return (joinstr);
}

/*
#include <stdio.h>
int main(void)
{
	char *s1 = "Hello, World!";
	char *s2 = " I'm chanwjeo.";

	printf("\n--------------------\n");
	printf("%s%s\n", "s1 : ", s1);
	printf("%s%s\n", "s2 : ", s2);
	printf("%s%s\n", "ft_strjoin(s1, s2) : ", ft_strjoin(s1, s2));
	return 0;
}
*/