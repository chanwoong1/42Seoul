/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/04 20:10:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdio.h>

int	print_num(long long num)
{
	int			i;
	char		pt[11];

	i = id_args_lens(num);
	pt[i] = '\0';
	while (i > 0)
	{
		pt[i - 1] = "0123456789"[num % 10];
		num /= 10;
		i--;
	}
	ft_putstr_fd(pt, 1);
	return (ft_strlen(pt));
}

int	print_id(va_list ap)
{
	long long	args;
	int			sign;

	args = va_arg(ap, int);
	sign = 0;
	if (args < 0)
	{
		sign = 1;
		args *= -1;
		write(1, "-", 1);
	}
	if (args > 2147483648)
		return (-1);
	return (print_num(args) + sign);
}

int	print_u(va_list ap)
{
	unsigned int	args;

	args = va_arg(ap, unsigned int);
	return (print_num((long long)args));
}

int	id_args_zero(t_flag *form_sp)
{
	int return_cnt;

	return_cnt = 0;
	if (form_sp->zero && !form_sp->precision)
		return (p_p('0', form_sp->width));
	if (!form_sp->width && form_sp->precision)
		return (p_p('0', form_sp->precision));
	if (form_sp->zero && form_sp->width > form_sp->precision)
	{
		if (form_sp->minus)
		{
			return_cnt += p_p('0', form_sp->precision);
			return_cnt += p_p(' ', form_sp->width - form_sp->precision);
		}
		else
		{
			return_cnt += p_p(' ', form_sp->width - form_sp->precision);
			return_cnt += p_p('0', form_sp->precision);
		}	
		return (return_cnt);
	}
	if (form_sp->dot != -1 && !form_sp->width)
		return_cnt = 0;
	else if (form_sp->dot != -1 && form_sp->precision)
	{
		if (form_sp->minus)
		{
			return_cnt += p_p('0', form_sp->precision);
			return_cnt += p_p(' ', form_sp->width - form_sp->precision);
		}
		else
		{
			return_cnt += p_p(' ', form_sp->width - form_sp->precision);
			return_cnt += p_p('0', form_sp->precision);
		}
		
	}
	else if (form_sp->dot != -1 && !form_sp->precision)
		return_cnt = p_p(' ', form_sp->width);
	else if (form_sp->dot == -1 && form_sp->width > 0)
	{
		return_cnt = p_p(' ', form_sp->width - 1);
		return_cnt += write(1, "0", 1);
	}
	else
		return_cnt = write(1, "0", 1);
	return (return_cnt);
}

int	print_with_id(t_flag *form_sp, va_list ap)
{
	long long	args;
	int			sign;
	int			return_cnt;

	args = va_arg(ap, int);
	sign = 0;
	return_cnt = 0;
	if (args == 0)
		return (id_args_zero(form_sp));
	if (args < 0)
	{
		sign = 1;
		args *= -1;
	}
	if (args > 2147483648)
		return (-1);
	return_cnt = id_args_non_zero(form_sp, args, sign);
	return (return_cnt);
}
