/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_precision_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:45:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/08 19:26:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	id_args_non_p_non_m_zero(t_flag *form_sp, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (sign)
	{
		r_c += write(1, "-", 1);
		r_c += p_p('0', form_sp->width - id_args_lens(args) - 1);
		r_c += print_num(args);
	}
	else
	{
		r_c += p_p('0', form_sp->width - id_args_lens(args));
		r_c += print_num(args);
	}
	return (r_c);
}

int	id_args_non_pre_non_minus(t_flag *form_sp, long long args, int sign)
{
	int	r_c;
	int	sps;

	r_c = 0;
	sps = 0;
	if (form_sp->zero)
		return (id_args_non_p_non_m_zero(form_sp, args, sign));
	if (form_sp->space && !form_sp->plus && !sign)
	{
		r_c += p_p(' ', form_sp->space);
		sps = 1;
	}
	if ((form_sp->width > id_args_lens(args) + 1) && form_sp->plus && sign)
		r_c += write(1, " ", 1);
	r_c += p_p(' ', form_sp->width - id_args_lens(args) - sps - form_sp->plus - sign);
	if (form_sp->plus && !sign)
		r_c += write(1, "+", 1);
	if (sign)
		r_c += write(1, "-", 1);
	r_c += print_num(args);
	return (r_c);
}

int	id_args_non_precision(t_flag *form_sp, long long args, int sign)
{
	int	r_c;

	r_c = 0;
	if (!form_sp->minus)
		r_c = id_args_non_pre_non_minus(form_sp, args, sign);
	else
	{
		if (form_sp->plus)
			r_c += write(1, "+", 1);
		else if (form_sp->space && !sign)
			r_c += write(1, " ", 1);
		if (sign)
			r_c += write(1, "-", 1);
		r_c += print_num(args);
		r_c += p_p(' ', form_sp->width - id_args_lens(args) - sign);
	}
	return (r_c);
}
