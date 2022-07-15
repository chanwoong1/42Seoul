/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:04:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/13 12:01:51 by chanwjeo         ###   ########.fr       */
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

	while (find_set(*s1, set))
		s1++;
	i = ft_strlen(s1);
	while (i > 0)
	{
		if (!(find_set(s1[i - 1], set)))
			break ;
		i--;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (0);
	j = 0;
	while (i > j)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
