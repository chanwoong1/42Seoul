/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:45:18 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/01 17:34:26 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	is_specifier(const char sp)
{
	char	charset[9] = "cspdiuxX%";
	int		idx;

	idx = 0;
	while (charset[idx])
	{
		if (charset[idx] == sp)
			return (idx);
		idx++;
	}
	return (-1);
}

int	is_printable(char **print, const char *format, va_list *ap)
{
	if (is_specifier(format[1]) == 0)
	{
		if (!ft_print_c(print, ap))
			return (0);
	}
	if (is_specifier(format[1]) == 1)
	{
		if (!ft_print_s(print, ap))
			return (0);
	}
	// if (is_specifier(format[1]) == 2)
	// 	if (!ft_print_p(print, ap))
	// 		return (0);
	return (1);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*args;
	char	*print;
	char	*tmp;

	va_start(ap, format);
	if (!(print = (char *)malloc(sizeof(char))))
		return (-1);
	print[0] = '\0';
	args = 0;
	while (*format)
	{
		if (*format == '%' && is_specifier(*(format + 1)) == -1)
			return (-1);
		else if (*format == '%' && is_specifier(*(format + 1)) >= 0)
		{
			if (!is_printable(&print, format, &ap))
				return (-1);
			format++;
		}
		else
		{
			if (!(tmp = ft_strjoin(print, (char *)format, 1)))
				return (-1);
			free(print);
			print = tmp;
		}
		format++;
	}
	ft_putstr_fd(print, 1);
	return (0);
}

int main(void)
{
    ft_printf("aaaa%cbbbb%ccccc%cdddd%c%c%s", '1', '2', '3', '\n', '5', "aknvlaskdnlk");
	return (0);
}
