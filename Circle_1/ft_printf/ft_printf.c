/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:13:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/03 11:01:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

int	ft_printf(const char *form, ...)
{
	va_list		ap;
	size_t		return_cnt;
	int			(*f[256])(va_list ap);
	char		val_f[256];
	long long	cnt;

	set_f_pt(f, val_f);
	va_start(ap, form);
	return_cnt = 0;
	while (*form)
	{
		if ((unsigned char)(*form) == '%' && val_f[(unsigned char)(*(++form))])
				cnt = f[(unsigned char)(*form++)](ap);
		else
			cnt = write(1, form++, 1);
		if (cnt == -1 || return_cnt > 2147483647)
			break ;
		return_cnt += cnt;
	}
	va_end(ap);
	if (cnt < 0 || return_cnt > 2147483647)
		return (-1);
	return ((int)return_cnt);
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
