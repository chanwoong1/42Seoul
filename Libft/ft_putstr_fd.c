/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:48:56 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 20:20:13 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &s[0], 1);
		s++;
	}
}

/*
#include <stdio.h>
int main(void)
{
	char *s = "abcdefg";

	ft_putstr_fd(s, 1);
	return (0);
}
*/