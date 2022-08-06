/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:33:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/06 12:45:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	print_with_percent_add(t_flag *form_sp)
{
	int	r_c;

	r_c = 0;
	if (form_sp->minus)
	{
		r_c = write(1, "%%", 1);
		r_c += p_p(' ', form_sp->width - 1);
	}
	else if (!(form_sp->minus) && form_sp->zero)
	{
		r_c = p_p('0', form_sp->width - 1);
		r_c += write(1, "%%", 1);
	}
	else
	{
		r_c = p_p(' ', form_sp->width - 1);
		r_c += write(1, "%%", 1);
	}	
	return (r_c);
}

int	print_with_percent(t_flag *form_sp)
{
	int	r_c;

	if (form_sp->width >= 1)
	{
		r_c = print_with_percent_add(form_sp);
	}
	else
		r_c = write(1, "%%", 1);
	return (r_c);
}

int	print_percent(va_list *ap)
{
	(void)*ap;
	write(1, "%%", 1);
	return (1);
}
