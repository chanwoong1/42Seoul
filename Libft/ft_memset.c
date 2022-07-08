/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:55:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/08 15:26:35 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((unsigned char *)b++) = (unsigned char)c;
	return (b);
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
	//memset(arr, 2, 4);
	ft_memset(arr, 2, 4);//arr의 메모리를 0으로 설정
	printf("==설정 후 ==\n");
	for(i=0; i<10; i++)
		printf("%s%d%s", "[", arr[i], "]");
	printf("\n");
	return 0;
}
*/
