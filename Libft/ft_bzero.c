/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/08 17:10:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)s++) = 0;
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int i;
	printf("==설정 전 ==\n");
	for(i=0; i<10; i++)
		printf("%s%d%s", "[", arr[i], "]");//쓰레기 값 출력
	printf("\n");
	//bzero(arr, 1);
	ft_bzero(arr, 4);//arr의 메모리를 0으로 설정
	printf("==설정 후 ==\n");
	for(i=0; i<10; i++)
		printf("%s%d%s", "[", arr[i], "]");
	printf("\n");
	return 0;
}
*/