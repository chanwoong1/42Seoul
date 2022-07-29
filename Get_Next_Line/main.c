/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:51:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/28 14:51:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*temp;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	temp = get_next_line(fd);
	while (temp != 0)
	{
		printf("%s", temp);
		free(temp);
		temp = get_next_line(fd);
	}
	printf("%s", temp);
	free(temp);
	close(fd);
	return (0);
	system("leaks a.out");
}
