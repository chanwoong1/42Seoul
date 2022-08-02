/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:42:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/02 17:34:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	print_c(va_list ap)
{
	char	args;

	args = va_arg(ap, int);
	ft_putchar_fd(args, 1);
	return (1);
}

int	print_s(va_list ap)
{
	char	*args;

	args = va_arg(ap, char *);
	if (!args)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(args, 1);
	return (ft_strlen(args));
}

int	print_p(va_list ap)
{
	unsigned char		*args;
	int					i;
	unsigned long long	tmp;
	char				pt[16];

	args = (unsigned char *)va_arg(ap, unsigned char *);
	tmp = (unsigned long long)args;
	i = 0;
	while (i++ < 15)
	{
		if (tmp < 16)
			break ;
		tmp /= 16;
	}
	tmp = (unsigned long long)args;
	pt[i] = '\0';
	while (i > 0)
	{
		pt[i - 1] = "0123456789abcdef"[tmp % 16];
		tmp /= 16;
		i--;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(pt, 1);
	return (ft_strlen(pt) + 2);
}

int	print_percent(va_list ap)
{
	void	*tmp;

	tmp = ap;
	write(1, "%%", 1);
	return (1);
}
