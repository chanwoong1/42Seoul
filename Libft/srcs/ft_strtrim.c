/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:04:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/17 14:39:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size;
	char		*copy;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	size = ft_strlen(s1);
	while (size > 0 && ft_strchr(set, s1[size - 1]))
		--size;
	copy = ft_substr(s1, 0, size);
	return (copy);
}
