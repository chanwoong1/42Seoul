/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:45:18 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/01 01:07:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*vars;

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
    ft_printf("sdnclknsd%s", "sonic1", "sonic2", "sonic3", "sonic4", "sonic5", "sonic6");
	retrun (0);
}