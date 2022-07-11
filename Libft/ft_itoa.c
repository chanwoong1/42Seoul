/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:36:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 19:15:23 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_size(int n)
{
	int				size;
	unsigned int	un;

	un = (unsigned int)n;
	size = 0;
	if (n < 0)
		size++;
	while (un > 10)
	{
		size++;
		un = un / 10;
	}
	return (size);
}

char	*put_itoa(char *c, int n, int size, unsigned int un)
{
	if (n < 0)
	{
		c[0] = '-';
		while (size > 0)
		{
			c[size] = (un % 10) + '0';
			un /= 10;
			size--;
		}
	}
	else
	{
		while (size >= 0)
		{
			c[size] = (un % 10) + '0';
			un /= 10;
			size--;
		}
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int				size;
	unsigned int	un;
	char			*c;

	un = (unsigned int)n;
	size = find_size(n);
	c = (char *)malloc(sizeof(char) * (size + 1));
	if (!c)
		return (0);
	return (put_itoa(c, n, size, un));
}

/*
#include <stdio.h>
int main(void)
{
	int	n1 = 2147483647;
	int n2 = -2147483648;
	int n3 = 'z';

	printf("--------------------\n");
	printf("%s%s\n", "n1 : ", ft_itoa(n1));
	printf("%s%s\n", "n2 : ", ft_itoa(n2));
	printf("%s%s\n", "n3 : ", ft_itoa(n3));
	return 0;
}
*/