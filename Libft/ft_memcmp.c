/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:19:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/14 18:30:06 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;

	uc1 = s1;
	uc2 = s2;
	if (n == 0)
		return (0);
	while (n > 1 && *uc1 == *uc2)
	{
		uc1++;
		uc2++;
		n--;
	}
	return (*uc1 - *uc2);
}
