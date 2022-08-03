/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:18:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/03 14:21:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdio.h>

static void	set_f_pt(int (*f[256])(va_list ap), char *val_f)
{
	ft_memset(f, 0, 256);
	ft_memset(val_f, 0, 256);
	f['d'] = print_id;
	f['i'] = print_id;
	f['c'] = print_c;
	f['p'] = print_p;
	f['s'] = print_s;
	f['u'] = print_u;
	f['x'] = print_x;
	f['X'] = print_xx;
	f['%'] = print_percent;
	val_f['d'] = 1;
	val_f['i'] = 1;
	val_f['c'] = 1;
	val_f['p'] = 1;
	val_f['s'] = 1;
	val_f['u'] = 1;
	val_f['x'] = 1;
	val_f['X'] = 1;
	val_f['%'] = 1;
}

void	set_info(t_list *form_sp)
{
	form_sp->type = '\0';
	form_sp->minus = 0;
	form_sp->zero = 0;
	form_sp->period = 0;
	form_sp->hash = 0;
	form_sp->space = 0;
	form_sp->width = 0;
	form_sp->precision = 0;
}

void	fill_info(t_list *form_sp, char *format, int *idx)
{
	if (format[*idx] == '-')
		form_sp->minus = 1;
	if (format[*idx] == '0')
		form_sp->minus = 1;
	if (format[*idx] == '.')
		form_sp->minus = 1;
	if (format[*idx] == '#')
		form_sp->minus = 1;
	if (format[*idx] == ' ')
		form_sp->minus = 1;
	if (format[*idx] == '+')
		form_sp->minus = 1;
	if (format[*idx] >= '0' && format[*idx] <= '9')
		form_sp->width = format[*idx] - '0';
}

int	init_parsing(char *format, int *idx, va_list ap)
{
	t_list	*form_sp;
	int		tmp_count;

	tmp_count = 0;
	(*idx)++;
	form_sp = malloc(sizeof(t_list));
	set_info(form_sp);
	while (ft_strchr("-0.# +123456789", format[*idx]))
	{
		fill_info(form_sp, format, *idx);
		(*idx)++;
	}
	if (ft_strchr("cspdiuxX%", format[*idx]))
	{
		form_sp->type = format[*idx];
		tmp_count += print_form_sp(form_sp, ap);
	}
	ft_free(form_sp);
	return (tmp_count);
}

// int	is_printf_flag(char *form, int *idx, va_list ap)
// {
// 	int		(*f[256])(va_list ap);
// 	char	val_f[256];
// 	int		return_cnt;

// 	set_f_pt(f, val_f);
// 	if (form[*idx] == )
// 	return (return_cnt);
// }

int	count_printf(char *form, va_list ap)
{
	size_t		return_cnt;
	long long	cnt;
	int			idx;
	int			*idx_pt;

	return_cnt = 0;
	idx = 0;
	idx_pt = &idx;
	while (form[idx])
	{
		if ((unsigned char)form[idx] == '%')
			cnt = is_printf_flag(form, idx + 1, ap);
		else
			cnt = write(1, form[idx], 1);
		if (cnt == -1 || return_cnt > 2147483647)
			return (-1) ;
		return_cnt += cnt;
		idx++;
	}
	return (return_cnt);
}

int	ft_printf(const char *form, ...)
{
	va_list		ap;
	int		return_cnt;

	va_start(ap, form);
	return_cnt = count_printf((char *)form, ap);
	va_end(ap);
	return (return_cnt);
}

int	main(void)
{
	printf("%5%\n");
	return (0);
}


// int main(void)
// {
// 	char	*str=  "Hello, World!";
// 	int 	num;
// 	unsigned int	un = 4294967295;
// 	int		mn = -2147483648;
// 	int		n = 2147483647;

// 	write(1, "ft_printf : ", 12);
//     num = ft_printf("%%%%%%\ns(null) : %s\nc : %c\ns(str) : %s\np(str) : %p\nd : %d\n-d : %d\ni : %i\nu : %u\nx : %x\nX : %X\n", NULL, '2', str, str, n, mn, mn, un, un, un);
// 	printf("\nft_printf num : %d", num);
// 	printf("\n\nprintf : ");
// 	num = printf("%%%%%%\ns(null) : %s\nc : %c\ns(str) : %s\np(str) : %p\nd : %d\n-d : %d\ni : %i\nu : %u\nx : %x\nX : %X\n", NULL, '2', str, str, n, mn, mn, un, un, un);
// 	printf("\nprintf num : %d", num);
// 	return (0);
// }
