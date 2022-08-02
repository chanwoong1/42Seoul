/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:07:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/02 20:10:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_x(va_list ap)
{
	unsigned int	args;
	unsigned int	tmp;
	char			pt[11];
	int				i;

	args = va_arg(ap, unsigned int);
	tmp = args;
	i = 0;
	while (i++ < 15)
	{
		if (tmp < 16)
			break ;
		tmp /= 16;
	}
	pt[i] = '\0';
	while (i > 0)
	{
		pt[i - 1] = "0123456789abcdef"[args % 16];
		args /= 16;
		i--;
	}
	ft_putstr_fd(pt, 1);
	return (ft_strlen(pt));
}

int	print_xx(va_list ap)
{
	unsigned int	args;
	unsigned int	tmp;
	char			pt[11];
	int				i;

	args = va_arg(ap, unsigned int);
	tmp = args;
	i = 0;
	while (i++ < 15)
	{
		if (tmp < 16)
			break ;
		tmp /= 16;
	}
	pt[i] = '\0';
	while (i > 0)
	{
		pt[i - 1] = "0123456789ABCDEF"[args % 16];
		args /= 16;
		i--;
	}
	ft_putstr_fd(pt, 1);
	return (ft_strlen(pt));
}
