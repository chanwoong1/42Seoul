/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:25:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/25 12:19:46 by chanwjeo         ###   ########.fr       */
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
		n = read(STDIN_FILENO, buf, BUFFER_SIZE);
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

// #include <unistd.h>
// #include <stdio.h>

// int main()
// {
//     printf("STDIN_FILENO:%u\n",STDIN_FILENO);
//     printf("STDOUT_FILENO:%u\n",STDOUT_FILENO);
//     printf("STDERR_FILENO:%u\n",STDERR_FILENO);
//     printf("FOPEN_MAX:%u\n",FOPEN_MAX);
//     return 0;
// }