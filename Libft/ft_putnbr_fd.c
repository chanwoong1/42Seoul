/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:24:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 20:45:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;

	if (n < 0)
		write(fd, "-", 1);
	un = (unsigned int)n;
	if (un < 10)
	{
		c = un + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(un / 10, fd);
		c = un % 10 + '0';
		write(fd, &c, 1);
	}	
}

/*
#include <stdio.h>
int main(void)
{
	int n1 = 2147483647;
	int n2 = -2147483648;
	int n3 = 0;

	ft_putnbr_fd(n1, 1);
	printf("\n");
	ft_putnbr_fd(n2, 1);
	printf("\n");
	ft_putnbr_fd(n3, 1);
	return (0);
}
*/