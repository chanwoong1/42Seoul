/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:22:43 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 14:29:17 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	id_args_zero_2(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (opt->minus)
	{
		r_c += p_p('0', opt->prec);
		r_c += p_p(' ', opt->width - opt->prec);
	}
	else
	{
		r_c += p_p(' ', opt->width - opt->prec);
		r_c += p_p('0', opt->prec);
	}
	return (r_c);
}

int	id_plus_no_zero(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (opt->dot == -1)
	{
		if (!opt->minus)
			r_c += p_p(' ', opt->width - 2);
		r_c += write(1, "+0", 2);
		if (opt->minus)
			r_c += p_p(' ', opt->width - 2);
	}
	else
	{
		if (!opt->minus)
			r_c += p_p(' ', opt->width - 1 - opt->prec);
		r_c += write(1, "+", 1);
		r_c += p_p('0', opt->prec);
		if (opt->minus)
			r_c += p_p(' ', opt->width - 1 - opt->prec);
	}
	return (r_c);
}

int	id_space_zero(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (opt->zero && opt->space && opt->dot == -1 && opt->width > 1)
	{
		r_c += write(1, " ", 1);
		r_c += p_p('0', opt->width - 1);
		return (r_c);
	}
	if (opt->space && opt->dot == -1 && opt->width > 1)
	{
		if (!opt->minus)
			r_c += p_p(' ', opt->width - 2);
		r_c += write(1, " ", 1);
		r_c += p_p('0', 1);
		if (opt->minus)
			r_c += p_p(' ', opt->width - 2);
		return (r_c);
	}
	return (id_space_zero_2(opt));
}

int	id_plus_and_zero(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (!opt->minus && opt->width > 0 && opt->dot != -1)
		r_c += p_p(' ', opt->width - 1 - opt->prec);
	r_c += write(1, "+", 1);
	if (!(opt->width > 0 && opt->dot != -1))
		r_c += p_p('0', opt->width - 2);
	r_c += p_p('0', opt->prec);
	if (opt->dot == -1)
		r_c += write(1, "0", 1);
	if (opt->minus && opt->width > 0 && opt->dot != -1)
		r_c += p_p(' ', opt->width - 1 - opt->prec);
	return (r_c);
}

int	id_args_zero(t_flag *opt)
{
	if (opt->plus && opt->zero)
		return (id_plus_and_zero(opt));
	if (opt->plus && !opt->zero)
		return (id_plus_no_zero(opt));
	if (opt->space)
		return (id_space_zero(opt));
	if (!opt->plus && opt->zero && opt->dot == -1)
	{
		if (!(opt->width) && (opt->sp == 'x' || opt->sp == 'X' \
			|| opt->sp == 'd' || opt->sp == 'u' || opt->sp == 'i'))
			return (p_p('0', 1));
		return (p_p('0', opt->width));
	}
	if (!opt->width && opt->dot != -1)
		return (p_p('0', opt->prec));
	if (!opt->plus && opt->zero && opt->width > opt->prec)
		return (id_args_zero_2(opt));
	return (id_args_zero_3(opt));
}
