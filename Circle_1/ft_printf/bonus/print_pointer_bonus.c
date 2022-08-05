/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:21:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 11:43:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdio.h>

// int	print_with_p(t_flag *form_sp, va_list ap)
// {
// 	unsigned long long	args;
// 	int				r_t;
// 	int				hashtag;

// 	r_t = 0;
// 	args = (unsigned long long)va_arg(ap, void *);
// 	if (args == 0)
// 		return (id_args_zero(form_sp));
// 	if (form_sp->hash)
// 		hashtag = 2;
// 	if (!form_sp->minus)
// 		r_t += p_p(' ', form_sp->width - hashtag - id_hex_lens(args));
// 	r_t += write(1, "0x", 2);
// 	r_t += print_x(args);
// 	if (form_sp->minus)
// 		r_t += p_p(' ', form_sp->width - hashtag - id_hex_lens(args));
// 	return (0);
// }

int	print_with_p(t_flag *form_sp, va_list ap)
{
	unsigned char		*args;
	int					i;
	unsigned long long	tmp;
	char				pt[17];
	int					r_c;

	r_c = 0;
	args = va_arg(ap, void *);
	tmp = (unsigned long long)args;
	i = 0;
	while (i < 16)
	{
		pt[15 - i] = "0123456789abcdef"[tmp % 16];
		tmp = tmp / 16;
		i++;
	}
	pt[16] = '\0';
	printf("pt = %s\n", pt);
	i = 0;
	while (pt[i] == '0')
		i++;
	if (i - 13 < form_sp->width)
	{
		r_c += p_p(' ', form_sp->width - i + 13);
		r_c += write(1, "0x", 2);
		if (!(form_sp->dot && !form_sp->prec))
			r_c += write(1, pt + i, 16 - i);
	}
	else
	{
		r_c += write(1, "0x", 2);
		r_c += write(1, pt + i, 16 - i);
	}
	return (r_c);
}
// 