/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_precision_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:11:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:48:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	id_args_prec_width_minus2(t_flag *opt, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (opt->plus)
		sign = 0;
	if (opt->prec > id_args_lens(args))
		r_c += p_p(' ', opt->width - opt->prec - sign - opt->plus);
	else
		r_c += p_p(' ', opt->width - id_args_lens(args) - sign - opt->plus);
	return (r_c);
}

int	id_args_prec_width_minus(t_flag *opt, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (!opt->minus && opt->space && !sign && id_args_lens(args) >= opt->width)
		r_c += write(1, " ", 1);
	else if (opt->minus && opt->space && !sign && opt->dot != -1 && !opt->plus)
	{
		r_c += write(1, " ", 1);
		opt->width -= 1;
	}
	if (!(opt->minus))
		r_c += id_args_prec_width_minus2(opt, args, sign);
	if (opt->plus && !sign)
		r_c += write(1, "+", 1);
	if (sign)
		r_c += write(1, "-", 1);
	r_c += p_p('0', opt->prec - id_args_lens(args));
	r_c += print_num(args);
	if (opt->minus)
		r_c += id_args_prec_width_minus2(opt, args, sign);
	return (r_c);
}

int	id_args_prec_width(t_flag *opt, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (opt->prec < opt->width)
		r_c = id_args_prec_width_minus(opt, args, sign);
	else
	{
		if (opt->plus && !sign)
			r_c += write(1, "+", 1);
		else if (opt->space && !sign)
			r_c += write(1, " ", 1);
		if (sign)
			r_c += write(1, "-", 1);
		r_c += p_p('0', opt->prec - id_args_lens(args));
		r_c += print_num(args);
	}
	return (r_c);
}

int	id_args_prec(t_flag *opt, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (opt->width > 0)
		r_c = id_args_prec_width(opt, args, sign);
	else
	{
		if (opt->plus && !sign)
			r_c += write(1, "+", 1);
		else if (opt->space && !sign)
			r_c += write(1, " ", 1);
		if (sign)
			r_c += write(1, "-", 1);
		r_c += p_p('0', opt->prec - id_args_lens(args));
		r_c += print_num(args);
	}
	return (r_c);
}

int	id_args_non_zero(t_flag *opt, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (opt->dot == -1)
		r_c = id_args_non_precision(opt, args, sign);
	else
		r_c = id_args_prec(opt, args, sign);
	return (r_c);
}
