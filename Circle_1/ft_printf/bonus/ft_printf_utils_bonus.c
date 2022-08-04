/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:31:36 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 08:21:13 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int	p_p(char c, int n)
{
	int	r_c;

	r_c = 0;
	while (n-- > 0)
		r_c += write(1, &c, 1);
	return (r_c);
}

void	set_info(t_flag *form_sp)
{
	form_sp->sp = '\0';
	form_sp->minus = 0;
	form_sp->zero = 0;
	form_sp->dot = -1;
	form_sp->hash = 0;
	form_sp->space = 0;
	form_sp->width = 0;
	form_sp->prec = 0;
}

void	info_get_zero(t_flag *form_sp)
{
	if (form_sp->dot > -1)
		form_sp->prec = form_sp->prec * 10;
	else if (form_sp->width)
		form_sp->width = form_sp->width * 10;
	else
		form_sp->zero = 1;
}

void	fill_info(t_flag *form_sp, char *format, int idx)
{
	if (ft_strchr("0", format[idx]))
		return (info_get_zero(form_sp));
	if (ft_strchr("-.# +", format[idx]))
	{
		if (format[idx] == '-')
			form_sp->minus = 1;
		else if (format[idx] == '.')
			form_sp->dot = 1;
		else if (format[idx] == '#')
			form_sp->hash = 1;
		else if (format[idx] == ' ')
			form_sp->space = 1;
		else if (format[idx] == '+')
			form_sp->plus = 1;
		return ;
	}
	if (ft_strchr("123456789", format[idx]))
	{
		if (form_sp->dot > -1)
			form_sp->prec = (form_sp->prec * 10) + (format[idx] - '0');
		else
			form_sp->width = (form_sp->width * 10) + (format[idx] - '0');
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
