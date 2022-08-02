/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:00:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/02 12:13:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	if (fd < 0)
		return ;
	ln = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	if (ln < 10)
	{
		c = ln + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		c = ln % 10 + '0';
		write(fd, &c, 1);
	}	
}
