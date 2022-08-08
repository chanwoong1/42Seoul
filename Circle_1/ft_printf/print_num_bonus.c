/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/08 13:21:07 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

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

int	print_id(va_list *ap)
{
	long long	args;
	int			sign;

	args = va_arg(*ap, int);
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

int	print_u(t_flag *form_sp, va_list *ap)
{
	int				r_c;
	unsigned int	args;

	args = va_arg(*ap, unsigned int);
	if (args == 0)
		return (id_args_zero(form_sp));
	r_c = 0;
	if (form_sp->minus)
	{
		r_c = print_num((long long)args);
		r_c += p_p(' ', form_sp->width - id_args_lens(args));
	}
	else
	{
		if (form_sp->prec < id_args_lens(args))
		{
			r_c = p_p(' ', form_sp->width - id_args_lens(args));
			r_c += print_num((long long)args);
		}
		else
		{
			r_c = p_p(' ', form_sp->width - form_sp->prec);
			r_c += p_p('0', form_sp->prec - id_args_lens(args));
			r_c += print_num((long long)args);
		}
	}
	return (r_c);
}

int	print_with_id(t_flag *form_sp, va_list *ap)
{
	long long	args;
	int			sign;
	int			r_c;

	args = va_arg(*ap, int);
	sign = 0;
	r_c = 0;
	if (args == 0)
		return (id_args_zero(form_sp));
	if (args < 0)
	{
		sign = 1;
		args *= -1;
	}
	if (args > 2147483648)
		return (-1);
	r_c = id_args_non_zero(form_sp, args, sign);
	return (r_c);
}
