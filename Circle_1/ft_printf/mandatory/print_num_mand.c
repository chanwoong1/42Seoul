/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:32 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 15:13:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	print_num(long long num)
{
	int			i;
	long long	tmp;
	char		pt[11];

	i = 0;
	tmp = num;
	while (i++ < 11)
	{
		if (tmp < 10)
			break ;
		tmp /= 10;
	}
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

int	print_u(va_list *ap)
{
	unsigned int	args;

	args = va_arg(*ap, unsigned int);
	return (print_num((long long)args));
}
