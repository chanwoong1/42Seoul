/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_zero_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:22:43 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 13:30:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	id_args_zero_2(t_flag *form_sp)
{
	int	r_c;

	r_c = 0;
	if (form_sp->minus)
	{
		r_c += p_p('0', form_sp->prec);
		r_c += p_p(' ', form_sp->width - form_sp->prec);
	}
	else
	{
		r_c += p_p(' ', form_sp->width - form_sp->prec);
		r_c += p_p('0', form_sp->prec);
	}
	return (r_c);
}

int	id_args_zero(t_flag *form_sp)
{
	int	r_c;

	r_c = 0;
	if (form_sp->zero && !form_sp->prec)
		return (p_p('0', form_sp->width));
	if (!form_sp->width && form_sp->prec)
		return (p_p('0', form_sp->prec));
	if (form_sp->zero && form_sp->width > form_sp->prec)
		return (id_args_zero_2(form_sp));
	if (form_sp->dot != -1 && !form_sp->width)
		r_c = 0;
	else if (form_sp->dot != -1 && form_sp->prec)
		r_c = id_args_zero_2(form_sp);
	else if (form_sp->dot != -1 && !form_sp->prec)
		r_c = p_p(' ', form_sp->width);
	else if (form_sp->dot == -1 && form_sp->width > 0)
	{
		r_c = p_p(' ', form_sp->width - 1);
		r_c += write(1, "0", 1);
	}
	else
		r_c = write(1, "0", 1);
	return (r_c);
}
