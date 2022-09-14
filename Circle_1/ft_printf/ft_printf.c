/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:18:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 13:48:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_opt(t_flag *opt, va_list *ap)
{
	int	r_c;

	r_c = 0;
	if (opt->sp == '%')
		r_c = print_with_percent(opt);
	else if (opt->sp == 'i' || opt->sp == 'd')
		r_c = print_with_id(opt, ap);
	else if (opt->sp == 'u')
		r_c = print_u(opt, ap);
	else if (opt->sp == 'x' || opt->sp == 'X')
		r_c = print_with_x(opt, ap);
	else if (opt->sp == 'p')
		r_c = print_with_p(opt, ap);
	else if (opt->sp == 'c')
		r_c = print_with_c(opt, ap);
	else if (opt->sp == 's')
		r_c = print_with_s(opt, ap);
	return (r_c);
}

int	is_printf_flag(char *format, int *idx, va_list *ap)
{
	t_flag	*opt;
	int		r_c;

	r_c = 0;
	(*idx)++;
	opt = malloc(sizeof(t_flag));
	set_info(opt);
	while (ft_strchr("-0.# +123456789", format[*idx]))
	{
		fill_info(opt, format, *idx);
		(*idx)++;
	}
	if (ft_strchr("cspdiuxX%", format[*idx]))
	{
		opt->sp = format[*idx];
		r_c = print_opt(opt, ap);
	}
	free(opt);
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
