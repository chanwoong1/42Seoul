/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:18:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/08 14:50:39 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"
#include <stdio.h>
int	print_form_sp(t_flag *form_sp, va_list *ap)
{
	int	r_c;

	// printf("form_sp->zero : %d\n", form_sp->zero);
	// printf("form_sp->prec : %d\n", form_sp->prec);
	// printf("form_sp->width : %d\n", form_sp->width);
	// printf("form_sp->hash : %d\n", form_sp->hash);
	// printf("form_sp->minus : %d\n", form_sp->minus);
	// printf("form_sp->dot : %d\n", form_sp->dot);
	r_c = 0;
	if (form_sp->sp == '%')
		r_c = print_with_percent(form_sp);
	else if (form_sp->sp == 'i' || form_sp->sp == 'd')
		r_c = print_with_id(form_sp, ap);
	else if (form_sp->sp == 'u')
		r_c = print_u(form_sp, ap);
	else if (form_sp->sp == 'x' || form_sp->sp == 'X')
		r_c = print_with_x(form_sp, ap);
	else if (form_sp->sp == 'p')
		r_c = print_with_p(form_sp, ap);
	else if (form_sp->sp == 'c')
		r_c = print_with_c(form_sp, ap);
	else if (form_sp->sp == 's')
		r_c = print_with_s(form_sp, ap);
	return (r_c);
}

int	is_printf_flag(char *format, int *idx, va_list *ap)
{
	t_flag	*form_sp;
	int		r_c;

	r_c = 0;
	(*idx)++;
	form_sp = malloc(sizeof(t_flag));
	set_info(form_sp);
	while (ft_strchr("-0.# +123456789", format[*idx]))
	{
		fill_info(form_sp, format, *idx);
		(*idx)++;
	}
	if (ft_strchr("cspdiuxX%", format[*idx]))
	{
		form_sp->sp = format[*idx];
		r_c = print_form_sp(form_sp, ap);
	}
	free(form_sp);
	return (r_c);
}

int	count_printf(char *form, va_list *ap)
{
	size_t		r_c;
	int			cnt;
	int			idx;
	int			*idx_pt;

	r_c = 0;
	cnt = 0;
	idx = 0;
	idx_pt = &idx;
	while (form[idx])
	{
		if (form[idx] == '%')
		{
			cnt = is_printf_flag(form, idx_pt, ap);
			if (cnt == -1)
				return (-1);
			r_c += cnt;
		}
		else
			r_c += write(1, &form[idx], 1);
		idx++;
	}
	return (r_c);
}

int	ft_printf(const char *form, ...)
{
	va_list	ap;
	int		r_c;

	va_start(ap, form);
	r_c = count_printf((char *)form, &ap);
	va_end(ap);
	return (r_c);
}
