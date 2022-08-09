/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:42:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 14:18:44 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	print_c(va_list *ap)
{
	unsigned char	args;

	args = va_arg(*ap, int);
	write(1, &args, 1);
	return (1);
}

int	print_with_c(t_flag *opt, va_list *ap)
{
	int	r_c;

	r_c = 0;
	if (!opt->minus)
		r_c += p_p(' ', opt->width - 1);
	r_c += print_c(ap);
	if (opt->minus)
		r_c += p_p(' ', opt->width - 1);
	return (r_c);
}

static int	print_s(char *args, int size)
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

static int	in_str_1(t_flag *opt, char *args, int len_args)
{
	int	r_c;

	r_c = 0;
	if (opt->prec > len_args)
	{
		if (!opt->minus)
			r_c += p_p(' ', opt->width - len_args);
		r_c += print_s(args, len_args);
		if (opt->minus)
			r_c += p_p(' ', opt->width - len_args);
	}
	else
	{
		if (!opt->minus)
			r_c += p_p(' ', opt->width - opt->prec);
		r_c += print_s(args, opt->prec);
		if (opt->minus)
			r_c += p_p(' ', opt->width - opt->prec);
	}
	return (r_c);
}

int	print_with_s(t_flag *opt, va_list *ap)
{
	int		r_c;
	char	*args;
	int		len_args;

	r_c = 0;
	args = va_arg(*ap, char *);
	if (!args)
		args = "(null)";
	len_args = ft_strlen(args);
	if (opt->dot != -1)
		r_c += in_str_1(opt, args, len_args);
	else
	{
		if (!opt->minus)
			r_c += p_p(' ', opt->width - len_args);
		r_c += print_s(args, len_args);
		if (opt->minus)
			r_c += p_p(' ', opt->width - len_args);
	}
	return (r_c);
}
