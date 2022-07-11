/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:04:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 15:24:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	while (find_set(*s1, set) == 0)
		s1++;
	while (s1[i])
		i++;
	while (i > 0)
	{
		if (find_set(s1[i - 1], set))
			break ;
		i--;
	}
	str = (char *)malloc(sizeof(char) * i);
	if (str == 0)
		return (0);
	j = 0;
	while (i > j)
	{
		str[j] = s1[j];
		j++;
	}
	return (str);
}

/*
#include <stdio.h>
int main(void)
{
	char *s = "Hello, World!";
	char *set = "ldr";

	printf("\n--------------------\n");
	printf("%s%s\n", "s : ", s);
	printf("%s%s\n", "set : ", set);
	printf("%s%s\n", "ft_strtrim(s, set) : ", ft_strtrim(s, set));
	return 0;
}
*/