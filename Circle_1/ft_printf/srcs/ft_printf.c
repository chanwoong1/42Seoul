/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:13:44 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/02 14:48:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

void	init_fuc_pointer(int (*fuc[256])(va_list ap), char *infuc)
{
	ft_memset(fuc, 0, 256);
	ft_memset(infuc, 0, 256);
	// fuc['d'] = print_dec_int;
	// fuc['i'] = print_dec_int;
	fuc['c'] = print_c;
	// fuc['p'] = print_addr;
	// fuc['s'] = print_str;
	// fuc['u'] = print_unsigned_int;
	// fuc['x'] = print_hex_lower;
	// fuc['X'] = print_hex_upper;
	// fuc['%'] = print_persent;
	infuc['d'] = 1;
	infuc['i'] = 1;
	infuc['c'] = 1;
	infuc['p'] = 1;
	infuc['s'] = 1;
	infuc['u'] = 1;
	infuc['x'] = 1;
	infuc['X'] = 1;
	infuc['%'] = 1;
}

int	is_specifier(const char sp)
{
	char	*charset;
	int		idx;

	charset = "cspdiuxX%";
	idx = 0;
	while (charset[idx])
	{
		if (charset[idx] == sp)
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_printf(const char *form, ...)
{
	va_list	ap;
	size_t	return_cnt;
	int		(*fuc[256])(va_list ap);
	char	infuc[256];
	int		cnt;

	init_fuc_pointer(fuc, infuc);
	va_start(ap, form);
	return_cnt = 0;
	while (*form)
	{
		if ((unsigned char)(*form) == '%' && infuc[(unsigned char)(*(++form))])
				cnt = fuc[(unsigned char)(*form++)](ap);
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

int main(void)
{
	// char	*str=  "Hello, World!";
	int	num;

	printf("ft_printf : ");
    num = ft_printf("aaaa%cbbbb\n%ccccc%cdddd%c%c%c", 'a', '2', '3', '\n', '5', 'a');
	printf("\nft_printf num : %d", num);
	printf("\n\nprintf : ");
	num = printf("aaaa%cbbbb\n%ccccc%cdddd%c%c%c", 'a', '2', '3', '\n', '5', 'a');
	printf("\nprintf num : %d", num);
	return (0);
}
