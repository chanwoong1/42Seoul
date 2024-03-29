/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:33:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:48:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_with_percent_add(t_flag *opt)
{
	int	r_c;

	r_c = 0;
	if (opt->minus)
	{
		r_c = write(1, "%%", 1);
		r_c += p_p(' ', opt->width - 1);
	}
	else if (!(opt->minus) && opt->zero)
	{
		r_c = p_p('0', opt->width - 1);
		r_c += write(1, "%%", 1);
	}
	else
	{
		r_c = p_p(' ', opt->width - 1);
		r_c += write(1, "%%", 1);
	}	
	return (r_c);
}

int	print_with_percent(t_flag *opt)
{
	int	r_c;

	if (opt->width >= 1)
	{
		r_c = print_with_percent_add(opt);
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
