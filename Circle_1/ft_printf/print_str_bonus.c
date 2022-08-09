/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:42:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:23:55 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_c(va_list *ap)
{
	unsigned char	args;

	args = va_arg(*ap, int);
	write(1, &args, 1);
	return (1);
}

int	print_with_c(t_flag *form_sp, va_list *ap)
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
	while (size > count)
	{
		write(1, args, 1);
		args++;
		count++;
	}
	return (count);
}

int	print_with_s(t_flag *form_sp, va_list *ap)
{
	int		r_c;
	char	*args;
	int		len_args;

	r_c = 0;
	args = va_arg(*ap, char *);
	if (!args)
		args = "(null)";
	len_args = ft_strlen(args);
	if (form_sp->dot != -1)
	{
		if (form_sp->prec > len_args)
		{
			if (!form_sp->minus)
				r_c += p_p(' ', form_sp->width - len_args);
			r_c += print_s(args, len_args);
			if (form_sp->minus)
				r_c += p_p(' ', form_sp->width - len_args);
		}
		else
		{
			if (!form_sp->minus)
				r_c += p_p(' ', form_sp->width - form_sp->prec);
			r_c += print_s(args, form_sp->prec);
			if (form_sp->minus)
				r_c += p_p(' ', form_sp->width - form_sp->prec);
		}
	}
	else
	{
		if (!form_sp->minus)
			r_c += p_p(' ', form_sp->width - len_args);
		r_c += print_s(args, len_args);
		if (form_sp->minus)
			r_c += p_p(' ', form_sp->width - len_args);
	}
	return (r_c);
}
