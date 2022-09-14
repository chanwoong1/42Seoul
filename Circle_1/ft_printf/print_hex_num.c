/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:07:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 14:12:07 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	len_args_hex(long num)
{
	int	len;

	len = 0;
	while (1)
	{
		++len;
		num /= 16;
		if (num == 0)
			return (len);
	}
}

int	print_x(unsigned int args)
{
	unsigned int	tmp;
	char			pt[11];
	int				i;

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

int	print_xx(unsigned int args)
{
	unsigned int	tmp;
	char			pt[11];
	int				i;

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

int	id_hex_lens(long long args)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = args;
	while (i++ < 11)
	{
		if (tmp < 16)
			break ;
		tmp /= 16;
	}
	return (i);
}

int	print_with_x(t_flag *opt, va_list *ap)
{
	unsigned int	args;
	int				len_args;
	int				r_c;
	int				hashtag;

	r_c = 0;
	hashtag = 0;
	args = va_arg(*ap, unsigned int);
	len_args = len_args_hex(args);
	if (args == 0)
		return (id_args_zero(opt));
	if (opt->hash)
		hashtag = 2;
	if (!opt->minus)
		r_c += in_hex_5(opt, args, hashtag, len_args);
	else
	{
		if (opt->width < opt->prec)
			r_c += in_hex_3(opt, args, hashtag);
		else
			r_c += in_hex_4(opt, args, hashtag, len_args);
	}
	return (r_c);
}
