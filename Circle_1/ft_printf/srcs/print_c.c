/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:42:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/02 14:59:02 by chanwjeo         ###   ########.fr       */
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
