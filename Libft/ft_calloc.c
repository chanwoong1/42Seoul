/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:59:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 12:30:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;

	if (count == 0 || size == 0)
		count = size - 1;
	ret = (void *)malloc(size * count);
	if (ret == (void *)0)
		return (0);
	return (ret);
}

/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int arr_1[5];	// 배열 선언
	int *arr_2;		// 포인터 변수 선언
	int *arr_3;
	int i;

	for(i = 0; i < 5; i++)
		arr_1[i] = i+1;
	arr_2 = (int*)calloc(5, sizeof(int));

	printf("-----calloc-----\n");
	for(i = 0; i < 5; i++)
	{
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}
	free(arr_2);
	printf("\n");
	printf("\n-----ft_calloc-----\n");
	arr_3 = (int *)ft_calloc(5, sizeof(int));

	for(i = 0; i < 5; i++)
	{
		arr_3[i] = arr_1[i];
		printf("%d ", arr_3[i]);
	}
	free(arr_3);
	return 0;
}
*/