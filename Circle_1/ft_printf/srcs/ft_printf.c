/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:45:18 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/01 01:32:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	is_valid_format(const char *format, va_list ap)
{
	char	*args;
	int		n_args;

	printf("format : %s\n", format);
	args = va_arg(ap, char *);
	n_args = 0;
	while (args)
	{
		n_args++;
		args = va_arg(ap, char *);
	}
	if (n_args == 0)
		return (0);
	return (n_args);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*vars;

	va_start(ap, format);
	if (!is_valid_format(format, ap))
		return (-1);
	va_start(ap, format);
	vars = va_arg(ap, char *);
	printf("format : %s\n", format);
	while (vars)
	{
		printf("vars : %s\n", vars);
		vars = va_arg(ap, char *);
	}
	return (0);
}

int main(void)
{
    ft_printf("sdn%sclk%dns%sd%s", "args1", "args2", "args3", "args4", "args5", "args6");
	return (0);
}