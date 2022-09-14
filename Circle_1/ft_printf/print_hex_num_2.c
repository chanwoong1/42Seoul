/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_num_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:55:36 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 14:10:29 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	in_hex_1(t_flag *opt, unsigned int args, int hashtag, int len_args)
{
	int	r_c;

	r_c = 0;
	if (hashtag == 2 && opt->sp == 'x')
		r_c += write(1, "0x", 2);
	if (hashtag == 2 && opt->sp == 'X')
		r_c += write(1, "0X", 2);
	if (opt->prec < hashtag + len_args)
		r_c += p_p('0', opt->width - hashtag - id_hex_lens(args));
	else
		r_c += p_p('0', opt->width - opt->prec);
	return (r_c);
}

int	in_hex_2(t_flag *opt, unsigned int args, int hashtag, int len_args)
{
	int	r_c;

	r_c = 0;
	if (opt->prec < len_args)
		r_c += p_p(' ', opt->width - hashtag - id_hex_lens(args));
	else
		r_c += p_p(' ', opt->width - hashtag - opt->prec);
	if (hashtag == 2 && opt->sp == 'x')
		r_c += write(1, "0x", 2);
	if (hashtag == 2 && opt->sp == 'X')
		r_c += write(1, "0X", 2);
	return (r_c);
}

int	in_hex_3(t_flag *opt, unsigned int args, int hashtag)
{
	int	r_c;

	r_c = 0;
	if (hashtag == 2 && opt->sp == 'x')
		r_c += write(1, "0x", 2);
	if (hashtag == 2 && opt->sp == 'X')
		r_c += write(1, "0X", 2);
	r_c += p_p('0', opt->prec - id_hex_lens(args));
	if (opt->sp == 'x')
		r_c += print_x(args);
	else
		r_c += print_xx(args);
	return (r_c);
}

int	in_hex_4(t_flag *opt, unsigned int args, int hashtag, int len_args)
{
	int	r_c;

	r_c = 0;
	if (opt->width < opt->prec)
		r_c += in_hex_3(opt, args, hashtag);
	else
	{
		if (hashtag == 2 && opt->sp == 'x')
			r_c += write(1, "0x", 2);
		if (hashtag == 2 && opt->sp == 'X')
			r_c += write(1, "0X", 2);
		r_c += p_p('0', opt->prec - id_hex_lens(args));
		if (opt->sp == 'x')
			r_c += print_x(args);
		else
			r_c += print_xx(args);
		if (opt->prec < len_args)
			r_c += p_p(' ', opt->width - hashtag - id_hex_lens(args));
		else
			r_c += p_p(' ', opt->width - hashtag - opt->prec);
	}
	return (r_c);
}

int	in_hex_5(t_flag *opt, unsigned int args, int hashtag, int len_args)
{
	int	r_c;

	r_c = 0;
	if (opt->zero && opt->dot == -1)
		r_c += in_hex_1(opt, args, hashtag, len_args);
	else
		r_c += in_hex_2(opt, args, hashtag, len_args);
	if (opt->dot)
		r_c += p_p('0', opt->prec - len_args);
	if (opt->sp == 'x')
		r_c += print_x(args);
	else
		r_c += print_xx(args);
	return (r_c);
}
