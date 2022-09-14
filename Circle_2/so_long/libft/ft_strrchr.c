/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:30:28 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/29 11:11:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ss;

	ss = s;
	while (*s)
		s++;
	while (*s != (char)c)
	{
		if (s == ss)
			return (0);
		s--;
	}
	return ((char *)s);
}
