/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_precision_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:11:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:13:39 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	id_args_prec_width_minus2(t_flag *form_sp, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (form_sp->plus)
		sign = 0;
	if (form_sp->prec > id_args_lens(args))
		r_c += p_p(' ', form_sp->width - form_sp->prec - sign - form_sp->plus);
	else
		r_c += p_p(' ', form_sp->width - id_args_lens(args) - sign - form_sp->plus);
	return (r_c);
}

int	id_args_prec_width_minus(t_flag *form_sp, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (!form_sp->minus && form_sp->space && !sign && id_args_lens(args) >= form_sp->width)
		r_c += write(1, " ", 1);
	else if (form_sp->minus && form_sp->space && !sign && form_sp->dot != -1 && !form_sp->plus)
	{
		r_c += write(1, " ", 1);
		form_sp->width -= 1;
	}
	if (!(form_sp->minus))
		r_c += id_args_prec_width_minus2(form_sp, args, sign);
	if (form_sp->plus && !sign)
		r_c += write(1, "+", 1);
	if (sign)
		r_c += write(1, "-", 1);
	r_c += p_p('0', form_sp->prec - id_args_lens(args));
	r_c += print_num(args);
	if (form_sp->minus)
		r_c += id_args_prec_width_minus2(form_sp, args, sign);
	if (form_sp->minus && form_sp->space && !sign && id_args_lens(args) >= form_sp->width)
		r_c += write(1, " ", 1);
	return (r_c);
}

int	id_args_prec_width(t_flag *form_sp, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (form_sp->prec < form_sp->width)
		r_c = id_args_prec_width_minus(form_sp, args, sign);
	else
	{
		if (form_sp->plus && !sign)
			r_c += write(1, "+", 1);
		else if (form_sp->space && !sign)
			r_c += write(1, " ", 1);
		if (sign)
			r_c += write(1, "-", 1);
		r_c += p_p('0', form_sp->prec - id_args_lens(args));
		r_c += print_num(args);
	}
	return (r_c);
}

int	id_args_prec(t_flag *form_sp, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (form_sp->width > 0)
		r_c = id_args_prec_width(form_sp, args, sign);
	else
	{
		if (form_sp->plus && !sign)
			r_c += write(1, "+", 1);
		else if (form_sp->space && !sign)
			r_c += write(1, " ", 1);
		if (sign)
			r_c += write(1, "-", 1);
		r_c += p_p('0', form_sp->prec - id_args_lens(args));
		r_c += print_num(args);
	}
	return (r_c);
}

int	id_args_non_zero(t_flag *form_sp, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (form_sp->dot == -1)
		r_c = id_args_non_precision(form_sp, args, sign);
	else
		r_c = id_args_prec(form_sp, args, sign);
	return (r_c);
}
