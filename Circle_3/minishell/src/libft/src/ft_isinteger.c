/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:25:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 20:20:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../include/libft.h"

bool	ft_isinteger(char *s)
{
	int			sign;
	size_t		sum;

	sum = 0;
	sign = 1;
	if (s[0] == '-' && s++)
		sign = -1;
	while (*s != '\0')
	{
		if (ft_isdigit(*s) == false)
			return (false);
		sum *= 10;
		sum += (*s - '0');
		s++;
	}
	if (sign < 0 && sum > ((size_t)INT_MAX + 1))
		return (false);
	else if (sign > 0 && sum > (size_t)INT_MAX)
		return (false);
	else
		return (true);
}
