/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:32:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/06 15:43:29 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*v;

	v = malloc(len);
	if (v == NULL)
		return (NULL);
	i = 0;
	while (v[i])
	{
		v[i] = c;
		i++;
	}
	i = 0;
	while (i < (unsigned int)len)
	{
		b[i] = v[i];
		i++;
	}
}

int main(void)
{
	char	*arr1 = "blockdmask blog";
	
	memset(arr1, 'c', 5 * sizeof(char));
	printf(arr1);
	return 0;
}
