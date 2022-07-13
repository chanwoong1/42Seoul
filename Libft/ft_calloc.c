/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:59:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/13 12:29:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;
	size_t			i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ret = (void *)malloc(size * count);
	if (ret == (void *)0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}
