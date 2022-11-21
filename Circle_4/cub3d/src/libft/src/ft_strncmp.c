/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:20:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 20:20:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_uchar;
	const unsigned char	*s2_uchar;

	s1_uchar = (const unsigned char *)s1;
	s2_uchar = (const unsigned char *)s2;
	while (*s1_uchar && *s2_uchar && (*s1_uchar == *s2_uchar) && n > 0)
	{
		s1_uchar++;
		s2_uchar++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((int)(*s1_uchar - *s2_uchar));
}
