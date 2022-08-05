/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:13:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 10:10:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	set_f_pt(int (*f[256])(va_list ap), char *val_f)
{
	ft_memset(f, 0, 256);
	ft_memset(val_f, 0, 256);
	f['d'] = print_id;
	f['i'] = print_id;
	f['c'] = print_c;
	f['p'] = print_p;
	f['s'] = print_s;
	f['u'] = print_u;
	f['x'] = print_x;
	f['X'] = print_xx;
	f['%'] = print_percent;
	val_f['d'] = 1;
	val_f['i'] = 1;
	val_f['c'] = 1;
	val_f['p'] = 1;
	val_f['s'] = 1;
	val_f['u'] = 1;
	val_f['x'] = 1;
	val_f['X'] = 1;
	val_f['%'] = 1;
}

int	ft_printf(const char *form, ...)
{
	va_list		ap;
	size_t		return_cnt;
	int			(*f[256])(va_list ap);
	char		val_f[256];
	long long	cnt;

	set_f_pt(f, val_f);
	va_start(ap, form);
	return_cnt = 0;
	while (*form)
	{
		if ((unsigned char)(*form) == '%' && val_f[(unsigned char)(*(++form))])
				cnt = f[(unsigned char)(*form++)](ap);
		else
			cnt = write(1, form++, 1);
		if (cnt == -1 || return_cnt > 2147483647)
			break ;
		return_cnt += cnt;
	}
	va_end(ap);
	if (cnt < 0 || return_cnt > 2147483647)
		return (-1);
	return ((int)return_cnt);
}
