/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:33:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/04 13:37:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int	print_with_percent_add(t_flag *form_sp)
{
	int return_cnt;

	return_cnt = 0;
	if (form_sp->minus)
	{
		return_cnt = write(1, "%%", 1);
		return_cnt = p_p(' ', form_sp->width - 1);
	}
	else if (!(form_sp->minus) && form_sp->zero)
	{
		return_cnt = p_p('0', form_sp->width - 1);
		return_cnt += write(1, "%%", 1);
	}
	else
	{
		return_cnt = p_p(' ', form_sp->width - 1);
		return_cnt += write(1, "%%", 1);
	}	
	return (return_cnt);
}

int	print_with_percent(t_flag *form_sp)
{
	int	return_cnt;

	if (form_sp->width >= 1)
	{
		return_cnt = print_with_percent_add(form_sp);
	}
	else
		return_cnt = write(1, "%%", 1);
	return (return_cnt);
}

int	print_percent(va_list ap)
{
	void	*tmp;

	tmp = ap;
	write(1, "%%", 1);
	return (1);
}
