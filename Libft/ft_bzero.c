/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:47 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/07 16:15:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)s++) = (unsigned char)'\0';
}


#include <string.h>
#include <stdio.h>
int main(void)
{
	int arr[10] = {0,};
	int i;
	printf("==설정 전 ==\n");
	for(i=0; i<10; i++)
		printf("%d", arr[i]);//쓰레기 값 출력
	printf("\n");
	//bzero(arr, 1);
	ft_bzero(arr, 1);//arr의 메모리를 0으로 설정
	printf("==설정 후 ==\n");
	for(i=0; i<10; i++)
		printf("%d",arr[i]);
	printf("\n");
	return 0;
}
