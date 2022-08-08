/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:21:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/08 15:31:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"
#include <stdio.h>

int	print_p(t_flag *form_sp, char *pt)
{
	int	i;
	int	r_c;

	i = 0;
	r_c = 0;
	while (pt[i] == '0')
		i++;
	if (i == 16)
		i -= 1;
	if (!form_sp->minus)
		r_c += p_p(' ', form_sp->width - (16 - i) - 2);
	r_c += write(1, "0x", 2);
	r_c += write(1, pt + i, 16 - i);
	if (form_sp->minus)
		r_c += p_p(' ', form_sp->width - (16 - i) - 2);
	return (r_c);
}

int	print_with_p(t_flag *form_sp, va_list *ap)
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
	r_c = print_p(form_sp, pt);
	return (r_c);
}
