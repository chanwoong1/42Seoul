/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:31:36 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:48:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	p_p(char c, int n)
{
	int	r_c;

	r_c = 0;
	while (n-- > 0)
		r_c += write(1, &c, 1);
	return (r_c);
}

void	set_info(t_flag *opt)
{
	opt->sp = '\0';
	opt->minus = 0;
	opt->zero = 0;
	opt->dot = -1;
	opt->hash = 0;
	opt->space = 0;
	opt->width = 0;
	opt->prec = 0;
	opt->plus = 0;
}

void	info_get_zero(t_flag *opt)
{
	if (opt->dot > -1)
		opt->prec = opt->prec * 10;
	else if (opt->width)
		opt->width = opt->width * 10;
	else
		opt->zero = 1;
}

void	fill_info(t_flag *opt, char *format, int idx)
{
	if (ft_strchr("0", format[idx]))
		return (info_get_zero(opt));
	if (ft_strchr("-.# +", format[idx]))
	{
		if (format[idx] == '-')
			opt->minus = 1;
		else if (format[idx] == '.')
			opt->dot = 1;
		else if (format[idx] == '#')
			opt->hash = 1;
		else if (format[idx] == ' ')
			opt->space = 1;
		else if (format[idx] == '+')
			opt->plus = 1;
		return ;
	}
	if (ft_strchr("123456789", format[idx]))
	{
		if (opt->dot > -1)
			opt->prec = (opt->prec * 10) + (format[idx] - '0');
		else
			opt->width = (opt->width * 10) + (format[idx] - '0');
	}
}

int	id_args_lens(long long args)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = args;
	while (i++ < 11)
	{
		if (tmp < 10)
			break ;
		tmp /= 10;
	}
	return (i);
}
