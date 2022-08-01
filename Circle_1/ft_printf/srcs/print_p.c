/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:29:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/02 01:12:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*print_memory(unsigned long long c, char *pt)
{
	int					i;
	unsigned long long	tmp;
	char	*base;
	int			idx;

	base = "0123456789abcdef";
	tmp = c;
	i = 0;
	while (i++ < 15)
	{
		if (tmp < 16)
			pt[i] = '0';
		tmp /= 16;
	}
	idx = 15;
	while (i < idx)
	{
		pt[idx] = base[c % 16];
		c /= 16;
		idx--;
	}
	return (pt);
}

int	ft_print_p(char **print, va_list *ap)
{
	unsigned long long	*args;
	char	*tmp;
	char	*mem_p;
	size_t	print_size;

	print_size = ft_strlen(*print);
	args = (unsigned long long)va_arg(*ap, void *);
	if (!(mem_p = (char *)malloc(sizeof(char) * 17)))
		return (0);
	mem_p[16] = '\0';
	mem_p = print_memory(args, mem_p);
	tmp = ft_strjoin(*print, args, 16);
	free(*print);
	*print = tmp;
	return (1);
}