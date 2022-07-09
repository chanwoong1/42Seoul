/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:13:43 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 15:15:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int	arr[10] = {'a', 'z', '1', '2', '3', '4', 'A', 'B', 'C', ' '};
	printf("--tolower--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", tolower(arr[i]), "]");
	printf("\n--ft_tolower--\n");
	for (int i = 0; i < 10; i++)
		printf("%s%c%s", "[", ft_tolower(arr[i]), "]");
	return (0);
}
*/