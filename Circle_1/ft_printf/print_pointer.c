/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:21:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:48:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	print_p(t_flag *opt, char *pt)
{
	int	i;
	int	r_c;

	i = 0;
	r_c = 0;
	while (pt[i] == '0')
		i++;
	if (i == 16)
		i -= 1;
	if (!opt->minus)
		r_c += p_p(' ', opt->width - (16 - i) - 2);
	r_c += write(1, "0x", 2);
	r_c += write(1, pt + i, 16 - i);
	if (opt->minus)
		r_c += p_p(' ', opt->width - (16 - i) - 2);
	return (r_c);
}

int	print_with_p(t_flag *opt, va_list *ap)
{
	unsigned char		*args;
	int					i;
	unsigned long long	tmp;
	char				pt[17];
	int					r_c;

	r_c = 0;
	args = va_arg(*ap, void *);
	tmp = (unsigned long long)args;
	i = 0;
	while (i < 16)
	{
		pt[15 - i] = "0123456789abcdef"[tmp % 16];
		tmp = tmp / 16;
		i++;
	}
	pt[16] = '\0';
	r_c = print_p(opt, pt);
	return (r_c);
}
