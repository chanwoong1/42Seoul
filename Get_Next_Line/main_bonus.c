/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:51:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/28 14:55:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text.txt", O_RDONLY);
	fd3 = open("text.txt", O_RDONLY);
	temp1 = get_next_line(fd1);
	temp2 = get_next_line(fd2);
	temp3 = get_next_line(fd3);
	while (temp1 != 0 && temp2 != 0 && temp3 != 0)
	{
		printf("%s", temp1);
		free(temp1);
		temp1 = get_next_line(fd1);
		printf("%s", temp2);
		free(temp2);
		temp2 = get_next_line(fd2);
		printf("%s", temp3);
		free(temp3);
		temp3 = get_next_line(fd3);
	}
	printf("%s", temp1);
	free(temp1);
	close(fd1);
	printf("%s", temp2);
	free(temp2);
	close(fd2);
	printf("%s", temp3);
	free(temp3);
	close(fd3);
	return (0);
}
