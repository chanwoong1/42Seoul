/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:21:17 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 14:37:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	id_space_zero_3(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (!opt->minus)
		r_c += p_p(' ', opt->width - opt->prec);
	else
		if (opt->space)
			r_c += write(1, " ", 1);
	return (r_c);
}

int	id_space_zero_2(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (opt->width <= 1)
		r_c += p_p(' ', opt->space);
	else if (opt->width > 0 && opt->dot != -1 && opt->prec == 0)
		r_c += p_p(' ', opt->width);
	else if (opt->width > 0 && opt->dot != -1 && opt->prec >= opt->width)
		r_c += p_p(' ', opt->space);
	else if (opt->width > 0 && opt->dot != -1 && opt->prec < opt->width)
		r_c += id_space_zero_3(opt);
	else
		r_c += p_p(' ', opt->width - 1);
	if (opt->dot == -1)
		r_c += write(1, "0", 1);
	else if (opt->dot != -1 && opt->prec > 0)
		r_c += p_p('0', opt->prec);
	if (opt->minus && opt->dot != -1 && opt->space && opt->prec > 0)
	{
		r_c += p_p(' ', opt->width - opt->prec - opt->space);
	}
	return (r_c);
}

int	id_args_zero_3(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (opt->dot != -1 && !opt->width)
		r_c = 0;
	else if (opt->dot != -1 && opt->prec)
		r_c = id_args_zero_2(opt);
	else if (opt->dot != -1 && !opt->prec)
		r_c = p_p(' ', opt->width);
	else if (opt->dot == -1 && opt->width > 0)
	{
		if (!opt->minus)
			r_c += p_p(' ', opt->width - 1);
		r_c += write(1, "0", 1);
		if (opt->minus)
			r_c += p_p(' ', opt->width - 1);
	}
	else
		r_c = write(1, "0", 1);
	return (r_c);
}
