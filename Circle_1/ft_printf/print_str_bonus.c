/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:42:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 13:30:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	print_c(va_list ap)
{
	unsigned char	args;

	args = va_arg(ap, int);
	ft_putchar_fd(args, 1);
	return (1);
}

int	print_with_c(t_flag *form_sp, va_list ap)
{
	int	r_c;

	r_c = 0;
	if (!form_sp->minus)
		r_c += p_p(' ', form_sp->width - 1);
	r_c += print_c(ap);
	if (form_sp->minus)
		r_c += p_p(' ', form_sp->width - 1);
	return (r_c);
}

int	print_s(char *args)
{
	ft_putstr_fd(args, 1);
	return (ft_strlen(args));
}

int	print_with_s(t_flag *form_sp, va_list ap)
{
	int		r_c;
	char	*args;

	r_c = 0;
	args = va_arg(ap, char *);
	if (!args)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	if (!form_sp->minus)
		r_c += p_p(' ', form_sp->width - ft_strlen(args));
	r_c += print_s(args);
	if (form_sp->minus)
		r_c += p_p(' ', form_sp->width - ft_strlen(args));
	return (r_c);
}
