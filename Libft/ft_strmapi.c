/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:16:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/13 12:56:12 by chanwjeo         ###   ########.fr       */
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
	if (map_s == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		map_s[j] = f(j, s[j]);
		j++;
	}
	map_s[j] = '\0';
	return (map_s);
}
