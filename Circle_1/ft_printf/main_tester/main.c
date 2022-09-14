/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:10:12 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 13:17:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main(void)
{
	char	*str=  "Hello, World!";
	int 	num;
	unsigned int	un = 4294967295;
	int		mn = -2147483648;
	int		n = 2147483647;

	write(1, "ft_printf : ", 12);
    num = ft_printf("%%%%%%\ns(null) : %s\np(null) : %p\nc : %c\ns(str) : %s\np(str) : %p\nd : %d\n-d : %d\ni : %i\nu : %u\nx : %x\nX : %X\n", NULL, NULL, '2', str, str, n, mn, mn, un, un, un);
	printf("\nft_printf num : %d", num);
	printf("\n\nprintf : ");
	num = printf("%%%%%%\ns(null) : %s\np(null) : %p\nc : %c\ns(str) : %s\np(str) : %p\nd : %d\n-d : %d\ni : %i\nu : %u\nx : %x\nX : %X\n", NULL, NULL, '2', str, str, n, mn, mn, un, un, un);
	printf("\nprintf num : %d", num);
	return (0);
}
