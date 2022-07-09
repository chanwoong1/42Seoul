/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:40:03 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 20:58:55 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (sign * ret);
}

/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	const char *str1 = "            +9584---12324asdca";
	const char *str2 = "  -12345aa123455";

	printf("----string----\n");
	printf("%s%s\n%s%s\n\n", "str1 : ", str1, "str2 : ", str2);
	printf("----atoi----\n");
	printf("%s%d\n", "atoi(str1) : ", atoi(str1));
	printf("%s%d\n\n", "atoi(str2) : ", atoi(str2));
	printf("----ft_atoi----\n");
	printf("%s%d\n", "ft_atoi(str1) : ", ft_atoi(str1));
	printf("%s%d\n", "ft_atoi(str2) : ", ft_atoi(str2));
}
*/