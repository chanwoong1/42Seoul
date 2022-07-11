/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:16:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 19:39:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*map_s;

	i = 0;
	while (s[i])
		i++;
	map_s = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		map_s[j] = f(j, s[j]);
		j++;
	}
	map_s[j] = '\0';
	return (map_s);	
}

/*
#include <stdio.h>
char mapi(unsigned int i, char c)
{
	return (c + i);
}
int main(void)
{
	char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaa";

	printf("-----------------------------\n");
	printf("%s%s\n", "s : ", s);
	printf("%s%s", "ft_strmapi(s) : ", ft_strmapi(s, &mapi));
	return (0);
}
*/