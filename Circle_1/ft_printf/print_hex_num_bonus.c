/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_num_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:07:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:23:55 by chanwjeo         ###   ########.fr       */
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

int	print_with_x(t_flag *form_sp, va_list *ap)
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
		return (id_args_zero(form_sp));
	if (form_sp->hash)
		hashtag = 2;
	if (!form_sp->minus)
	{
		if (form_sp->zero && form_sp->dot == -1)
		{
			if (hashtag == 2 && form_sp->sp == 'x')
				r_c += write(1, "0x", 2);
			if (hashtag == 2 && form_sp->sp == 'X')
				r_c += write(1, "0X", 2);
			if (form_sp->prec < hashtag + len_args)
				r_c += p_p('0', form_sp->width - hashtag - id_hex_lens(args));
			else
				r_c += p_p('0', form_sp->width - form_sp->prec);
		}
		else
		{
			if (form_sp->prec < len_args)
				r_c += p_p(' ', form_sp->width - hashtag - id_hex_lens(args));
			else
				r_c += p_p(' ', form_sp->width - hashtag - form_sp->prec);
			if (hashtag == 2 && form_sp->sp == 'x')
				r_c += write(1, "0x", 2);
			if (hashtag == 2 && form_sp->sp == 'X')
				r_c += write(1, "0X", 2);
		}
		if (form_sp->dot)
			r_c += p_p('0', form_sp->prec - len_args);
		if (form_sp->sp == 'x')
			r_c += print_x(args);
		else
			r_c += print_xx(args);
	}
	else
	{
		if (form_sp->width < form_sp->prec)
		{
			if (hashtag == 2 && form_sp->sp == 'x')
				r_c += write(1, "0x", 2);
			if (hashtag == 2 && form_sp->sp == 'X')
				r_c += write(1, "0X", 2);
			r_c += p_p('0', form_sp->prec - id_hex_lens(args));
			if (form_sp->sp == 'x')
				r_c += print_x(args);
			else
				r_c += print_xx(args);
		}
		else
		{
			if (hashtag == 2 && form_sp->sp == 'x')
				r_c += write(1, "0x", 2);
			if (hashtag == 2 && form_sp->sp == 'X')
				r_c += write(1, "0X", 2);
			r_c += p_p('0', form_sp->prec - id_hex_lens(args));
			if (form_sp->sp == 'x')
				r_c += print_x(args);
			else
				r_c += print_xx(args);
			if (form_sp->prec < len_args)
				r_c += p_p(' ', form_sp->width - hashtag - id_hex_lens(args));
			else
				r_c += p_p(' ', form_sp->width - hashtag - form_sp->prec);
		}		
	}
	return (r_c);
}
