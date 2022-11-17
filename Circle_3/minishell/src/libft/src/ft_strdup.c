/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:28:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 20:20:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

extern size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tmp;

	size = ft_strlen(s1);
	tmp = malloc(sizeof(*tmp) * (size + 1));
	if (!tmp)
		return (NULL);
	while (size > 0)
	{
		tmp[size] = s1[size];
		--size;
	}
	tmp[0] = s1[0];
	return (tmp);
}
