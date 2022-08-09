/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:45:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:53:13 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	id_args_non_p_non_m_zero(t_flag *opt, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (sign)
	{
		r_c += write(1, "-", 1);
		r_c += p_p('0', opt->width - id_args_lens(args) - 1);
		r_c += print_num(args);
	}
	else
	{
		if (opt->space && !(opt->zero && opt->space && opt->plus) \
			&& !opt->minus)
			r_c += write(1, " ", 1);
		if (opt->plus)
			r_c += write(1, "+", 1);
		if (opt->zero && opt->space && opt->plus)
			r_c += write(1, "0", 1);
		r_c += p_p('0', opt->width - id_args_lens(args) \
					- opt->plus - opt->space);
		r_c += print_num(args);
	}
	return (r_c);
}

int	id_args_non_pre_non_minus(t_flag *opt, long long args, int sign)
{
	int	r_c;
	int	sps;

	r_c = 0;
	sps = 0;
	if (opt->zero)
		return (id_args_non_p_non_m_zero(opt, args, sign));
	if (opt->space && !opt->plus && !sign)
	{
		r_c += p_p(' ', opt->space);
		sps = 1;
	}
	if ((opt->width > id_args_lens(args) + 1) && opt->plus && sign)
		r_c += write(1, " ", 1);
	r_c += p_p(' ', opt->width - id_args_lens(args) - sps - opt->plus - sign);
	if (opt->plus && !sign)
		r_c += write(1, "+", 1);
	if (sign)
		r_c += write(1, "-", 1);
	r_c += print_num(args);
	return (r_c);
}

int	id_args_non_precision(t_flag *opt, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (!opt->minus)
		r_c = id_args_non_pre_non_minus(opt, args, sign);
	else
	{
		if (opt->plus && !sign)
			r_c += write(1, "+", 1);
		else if (opt->space && !sign)
			r_c += write(1, " ", 1);
		if (sign)
			r_c += write(1, "-", 1);
		if (sign && (opt->plus || opt->space))
			sign = 0;
		r_c += print_num(args);
		r_c += p_p(' ', opt->width - opt->space - id_args_lens(args) \
						- sign - opt->plus);
	}
	return (r_c);
}
