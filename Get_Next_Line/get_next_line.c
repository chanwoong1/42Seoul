/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:25:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/25 11:27:39 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;

	if (fd > 0)
	{
		buf = (char *)malloc(256);
		if (!buf)
			return (FAIL);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
	}
}

int	main(void)
{
	while (1)
	{
		if (get_next_line(3) == FAIL)
			return (0);
	}
}