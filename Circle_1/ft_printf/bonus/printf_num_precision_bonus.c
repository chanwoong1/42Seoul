/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num_precision_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:45:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/04 17:41:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int	id_args_non_p_non_m_zero(t_flag *form_sp, long long args, int sign)
{
	int return_cnt;

	return_cnt = 0;
	if (sign)
	{
		return_cnt += write(1, "-", 1);
		return_cnt += p_p('0', form_sp->width - id_args_lens(args) - 1);
		return_cnt += print_num(args);
	}
	else
	{
		return_cnt += p_p('0', form_sp->width - id_args_lens(args));
		return_cnt += print_num(args);
	}
	return (return_cnt);
}

int	id_args_non_pre_non_minus(t_flag *form_sp, long long args, int sign)
{
	int return_cnt;

	return_cnt = 0;
	if (form_sp->zero)
		return (id_args_non_p_non_m_zero(form_sp, args, sign));
	if (form_sp->space && !form_sp->plus && !sign)
		return_cnt += p_p(' ', form_sp->space);
	if (form_sp->plus && !sign)
		return_cnt += write(1, "+", 1);
	return_cnt += p_p(' ', form_sp->width - id_args_lens(args) - sign);
	if (sign)
		return_cnt += write(1, "-", 1);
	return_cnt += print_num(args);
	return (return_cnt);
}

int	id_args_non_precision(t_flag *form_sp, long long args, int sign)
{
	int return_cnt;

	return_cnt = 0;
	if (!form_sp->minus)
		return_cnt = id_args_non_pre_non_minus(form_sp, args, sign);
	else
	{
		if (form_sp->plus)
			return_cnt += write(1, "+", 1);
		else if (form_sp->space && !sign)
			return_cnt += write(1, " ", 1);
		if (sign)
			return_cnt += write(1, "-", 1);
		return_cnt += print_num(args);
		return_cnt += p_p(' ', form_sp->width - id_args_lens(args) - sign);
	}
	return (return_cnt);
}
