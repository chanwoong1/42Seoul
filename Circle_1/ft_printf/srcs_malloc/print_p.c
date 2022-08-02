/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:29:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/02 11:53:20 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*print_memory(unsigned long long c)
{
	int					i;
	unsigned long long	tmp;
	char	*base;
	char	*pt;

	base = "0123456789abcdef";
	tmp = c;
	i = 0;
	while (i++ < 15)
	{
		if (tmp < 16)
			break;
		tmp /= 16;
	}
	if (!(pt = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	pt[i + 2] = '\0';
	while (i > 0)
	{
		pt[i + 1] = base[c % 16];
		c /= 16;
		i--;
	}
	return (pt);
}

int	ft_print_p(char **print, va_list *ap)
{
	unsigned char	*args;
	char	*tmp;
	char	*mem_p;
	size_t	print_size;

	print_size = ft_strlen(*print);
	args = (unsigned char *)va_arg(*ap, unsigned char *);
	if (!(mem_p = print_memory((unsigned long long)args)))
		return (0);
	mem_p[1] = 'x';
	mem_p[0] = '0';
	tmp = ft_strjoin(*print, mem_p, 16);
	free(*print);
	*print = tmp;
	return (1);
}