/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_precision_bonus_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:11:26 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/04 20:55:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdio.h>

int	id_args_prec_width_minus2(t_flag *form_sp, long long args, int sign)
{
	int	return_cnt;

	return_cnt = 0;
	if (form_sp->plus && sign)
		return_cnt += write(1, " ", 1);
	if (form_sp->precision > id_args_lens(args))
		return_cnt += p_p(' ', form_sp->width - form_sp->precision - sign - form_sp->plus);
	else
		return_cnt += p_p(' ', form_sp->width - id_args_lens(args) - sign - form_sp->plus);
	return (return_cnt);
}

int	id_args_prec_width_minus(t_flag *form_sp, long long args, int sign)
{
	int	return_cnt;

	return_cnt = 0;
	if (!(form_sp->minus))
		return_cnt += id_args_prec_width_minus2(form_sp, args, sign);
	if (form_sp->plus && !sign)
		return_cnt += write(1, "+", 1);
	if (sign)
		return_cnt += write(1, "-", 1);
	return_cnt += p_p('0', form_sp->precision - id_args_lens(args));
	return_cnt += print_num(args);
	if (form_sp->minus)
		return_cnt += id_args_prec_width_minus2(form_sp, args, sign);
	return_cnt = 0;
}

int	id_args_prec_width(t_flag *form_sp, long long args, int sign)
{
	int return_cnt;

	return_cnt = 0;
	if (form_sp->precision < form_sp->width)
		return_cnt = id_args_prec_width_minus(form_sp, args, sign);
	else
	{
		if (form_sp->plus && !sign)
			return_cnt += write(1, "+", 1);
		else if (form_sp->space && !sign)
			return_cnt += write(1, " ", 1);
		if (sign)
			return_cnt += write(1, "-", 1);
		return_cnt += p_p('0', form_sp->precision - id_args_lens(args));
		return_cnt += print_num(args);
	}
	return (return_cnt);
}

int	id_args_prec(t_flag *form_sp, long long args, int sign)
{
	int return_cnt;

	return_cnt = 0;
	if (form_sp->width > 0)
		return_cnt = id_args_prec_width(form_sp, args, sign);
	else
	{
		if (form_sp->space && form_sp->plus)
			return_cnt += write(1, "+", 1);
		else if (form_sp->space && !sign)
			return_cnt += write(1, " ", 1);
		if (sign)
			return_cnt += write(1, "-", 1);
		return_cnt += p_p('0', form_sp->precision - id_args_lens(args));
		return_cnt += print_num(args);
	}
	return (return_cnt);
}

int	id_args_non_zero(t_flag *form_sp, long long args, int sign)
{
	int	return_cnt;

	// printf("minus : %d\n", form_sp->minus);
	// printf("plus : %d\n", form_sp->plus);
	// printf("space : %d\n", form_sp->space);
	// printf("precision : %d\n", form_sp->precision);
	// printf("width : %d\n", form_sp->width);
	// printf("zero : %d\n", form_sp->zero);
	return_cnt = 0;
	if (!form_sp->precision)
		return_cnt = id_args_non_precision(form_sp, args, sign);
	else
		return_cnt = id_args_prec(form_sp, args, sign);
	return (return_cnt);
}