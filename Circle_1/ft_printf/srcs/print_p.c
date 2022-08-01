/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:29:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/01 16:35:39 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_memory(unsigned long long c)
{
	int					i;
	unsigned long long	tmp;

	tmp = c;
	i = 0;
	while (i++ < 15)
	{
		if (tmp < 16)
			ft_putchar('0', 1);
		tmp /= 16;
	}
	change_hexa(c, 0);
}

int	ft_print_p(char **print, va_list *ap)
{
	char	*args;
	char	*tmp;
	char	*mem_p;
	size_t	print_size;

	print_size = ft_strlen(*print);
	args = (unsigned long long)va_arg(*ap, void *);
	if (!(mem_p = (char *)malloc(sizeof(char) * 17)))
		return (0);
	tmp = ft_strjoin(*print, args, 16);
	free(*print);
	*print = tmp;
	return (1);
}