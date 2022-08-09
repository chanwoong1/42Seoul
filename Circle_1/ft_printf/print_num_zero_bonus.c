/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_zero_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:22:43 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:23:55 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

int id_plus_no_zero(t_flag *form_sp)
{
	int	r_c;

	r_c = 0;
	if (form_sp->dot == -1)
	{
		if (!form_sp->minus)
			r_c += p_p(' ', form_sp->width - 2);
		r_c += write(1, "+0", 2);
		if (form_sp->minus)
			r_c += p_p(' ', form_sp->width - 2);
	}
	else
	{
		if (!form_sp->minus)
			r_c += p_p(' ', form_sp->width - 1 - form_sp->prec);
		r_c += write(1, "+", 1);
		r_c += p_p('0', form_sp->prec);
		if (form_sp->minus)
			r_c += p_p(' ', form_sp->width - 1 - form_sp->prec);
	}
	return (r_c);
}

int	id_space_zero(t_flag *form_sp)
{
	int	r_c;

	r_c = 0;
	if (form_sp->zero && form_sp->space && form_sp->dot == -1 && form_sp->width > 1)
	{
		r_c += write(1, " ", 1);
		r_c += p_p('0', form_sp->width - 1);
		return (r_c);
	}
	if (form_sp->space && form_sp->dot == -1 && form_sp->width > 1)
	{
		if (!form_sp->minus)
			r_c += p_p(' ', form_sp->width - 2);
		r_c += write(1, " ", 1);
		r_c += p_p('0', 1);
		if (form_sp->minus)
			r_c += p_p(' ', form_sp->width - 2);
		return (r_c);
	}
	if (form_sp->width <= 1)
		r_c += p_p(' ', form_sp->space);
	else if (form_sp->width > 0 && form_sp->dot != -1 && form_sp->prec == 0)
		r_c += p_p(' ', form_sp->width);
	else if (form_sp->width > 0 && form_sp->dot != -1 && form_sp->prec >= form_sp->width)
		r_c += p_p(' ', form_sp->space);
	else if (form_sp->width > 0 && form_sp->dot != -1 && form_sp->prec < form_sp->width)
	{
		if (!form_sp->minus)
			r_c += p_p(' ', form_sp->width - form_sp->prec);
		else
			if (form_sp->space)
				r_c += write(1, " ", 1);
	}
	else
		r_c += p_p(' ', form_sp->width - 1);
	if (form_sp->dot == -1)
		r_c += write(1, "0", 1);
	else if (form_sp->dot != -1 && form_sp->prec > 0)
		r_c += p_p('0', form_sp->prec);
	if (form_sp->minus && form_sp->dot != -1 && form_sp->space && form_sp->prec > 0)
	{
		r_c += p_p(' ', form_sp->width - form_sp->prec - form_sp->space);
	}
	return (r_c);
}

int	id_plus_and_zero(t_flag *form_sp)
{
	int	r_c;
	
	r_c = 0;
	if (!form_sp->minus && form_sp->width > 0 && form_sp->dot != -1)
		r_c += p_p(' ', form_sp->width - 1 - form_sp->prec);
	r_c += write(1, "+", 1);
	if (!(form_sp->width > 0 && form_sp->dot != -1))
		r_c += p_p('0', form_sp->width - 2);
	r_c += p_p('0', form_sp->prec);
	if (form_sp->dot == -1)
		r_c += write(1, "0", 1);
	if (form_sp->minus && form_sp->width > 0 && form_sp->dot != -1)
		r_c += p_p(' ', form_sp->width - 1 - form_sp->prec);
	return (r_c);
}

int	id_args_zero(t_flag *form_sp)
{
	int	r_c;

	r_c = 0;
	if (form_sp->plus && form_sp->zero)
		return (id_plus_and_zero(form_sp));
	if (form_sp->plus && !form_sp->zero)
		return (id_plus_no_zero(form_sp));
	if (form_sp->space)
		return (id_space_zero(form_sp));
	if (!form_sp->plus && form_sp->zero && form_sp->dot == -1)
	{
		if (!(form_sp->width) && (form_sp->sp == 'x' || form_sp->sp == 'X' 
			|| form_sp->sp == 'd' || form_sp->sp == 'u' || form_sp->sp == 'i'))
			return (p_p('0', 1));
		return (p_p('0', form_sp->width));
	}
	if (!form_sp->width && form_sp->dot != -1)
		return (p_p('0', form_sp->prec));
	if (!form_sp->plus && form_sp->zero && form_sp->width > form_sp->prec)
		return (id_args_zero_2(form_sp));
	if (form_sp->dot != -1 && !form_sp->width)
		r_c = 0;
	else if (form_sp->dot != -1 && form_sp->prec)
		r_c = id_args_zero_2(form_sp);
	else if (form_sp->dot != -1 && !form_sp->prec)
		r_c = p_p(' ', form_sp->width);
	else if (form_sp->dot == -1 && form_sp->width > 0)
	{
		if (!form_sp->minus)
			r_c += p_p(' ', form_sp->width - 1);
		r_c += write(1, "0", 1);
		if (form_sp->minus)
			r_c += p_p(' ', form_sp->width - 1);
	}
	else
		r_c = write(1, "0", 1);
	return (r_c);
}
