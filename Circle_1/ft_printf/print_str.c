/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:42:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 15:13:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_c(va_list *ap)
{
	char	args;

	args = va_arg(*ap, int);
	ft_putchar_fd(args, 1);
	return (1);
}

int	print_s(va_list *ap)
{
	char	*args;

	args = va_arg(*ap, char *);
	if (!args)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(args, 1);
	return (ft_strlen(args));
}

int	print_p(va_list *ap)
{
	unsigned char		*args;
	int					i;
	unsigned long long	tmp;
	char				pt[17];

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
	i = 0;
	while (pt[i] == '0')
		i++;
	if (write(1, "0x", 2) < 0)
		return (-1);
	if (write(1, pt + i, 16 - i) < 0)
		return (-1);
	if (i == 16)
		return (2 + write(1, "0", 1));
	return (2 + 16 - i);
}

int	print_percent(va_list *ap)
{
	void	*tmp;

	tmp = *ap;
	write(1, "%%", 1);
	return (1);
}
