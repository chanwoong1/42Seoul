/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:42:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/07 14:36:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	print_c(va_list ap)
{
	unsigned char	args;

	args = va_arg(ap, int);
	write(1, &args, 1);
	return (1);
}

int	print_with_c(t_flag *form_sp, va_list ap)
{
	int	r_c;

	r_c = 0;
	if (!form_sp->minus)
		r_c += p_p(' ', form_sp->width - 1);
	r_c += print_c(ap);
	if (form_sp->minus)
		r_c += p_p(' ', form_sp->width - 1);
	return (r_c);
}

int	print_s(char *args, int size)
{
	int	count;

	count = 0;
	if (args == NULL)
		return (0);
	while (size > count)
	{
		write(1, args, 1);
		args++;
		count++;
	}
	return (count - 1);
}

int	print_with_s(t_flag *form_sp, va_list ap)
{
	int		r_c;
	char	*args;

	r_c = 0;
	args = va_arg(ap, char *);
	if (!args)
		args = "(null)";
	if (!form_sp->minus)
		r_c += p_p(' ', form_sp->width - ft_strlen(args));
	r_c += print_s(args, ft_strlen(args));
	if (form_sp->minus)
		r_c += p_p(' ', form_sp->width - ft_strlen(args));
	return (r_c);
}
