/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:48:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

int	print_u(t_flag *opt, va_list *ap)
{
	int				r_c;
	unsigned int	args;

	args = va_arg(*ap, unsigned int);
	if (args == 0)
		return (id_args_zero(opt));
	r_c = id_args_non_zero(opt, args, 0);
	return (r_c);
}

int	print_with_id(t_flag *opt, va_list *ap)
{
	long long	args;
	int			sign;
	int			r_c;

	args = va_arg(*ap, int);
	sign = 0;
	r_c = 0;
	if (args == 0)
		return (id_args_zero(opt));
	if (args < 0)
	{
		sign = 1;
		args *= -1;
	}
	if (args > 2147483648)
		return (-1);
	r_c = id_args_non_zero(opt, args, sign);
	return (r_c);
}
