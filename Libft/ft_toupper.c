/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:02:40 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 15:10:01 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int	arr[10] = {'a', 'z', '1', '2', '3', '4', 'A', 'B', 'C', ' '};
	printf("--toupper--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", toupper(arr[i]), "]");
	printf("\n--ft_toupper--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", ft_toupper(arr[i]), "]");
	return (0);
}
*/