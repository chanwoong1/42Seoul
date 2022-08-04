/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:31:36 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/04 13:37:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int	p_p(char c, int n)
{
	int return_cnt;

	return_cnt = 0;
	while (n-- > 0)
		return_cnt += write(1, &c, 1);
	return (return_cnt);
}

void	set_info(t_flag *form_sp)
{
	form_sp->sp = '\0';
	form_sp->minus = 0;
	form_sp->zero = 0;
	form_sp->dot = 0;
	form_sp->hash = 0;
	form_sp->space = 0;
	form_sp->width = 0;
	form_sp->precision = -1;
}

void	fill_info(t_flag *form_sp, char *format, int idx)
{
	if (format[idx] == '-')
		form_sp->minus = 1;
	if (!(format[idx - 1] == '.') && format[idx] == '0')
		form_sp->zero = 1;
	if (format[idx] == '.')
		form_sp->dot = 1;
	if (format[idx] == '#')
		form_sp->hash = 1;
	if (format[idx] == ' ')
		form_sp->space = 1;
	if (format[idx] == '+')
		form_sp->plus = 1;
	if (format[idx] >= '1' && format[idx] <= '9')
		form_sp->width = format[idx] - '0';
	if (form_sp->dot == 1 && format[idx] >= '0' && format[idx] <= '9')
		form_sp->precision = format[idx] - '0';
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