/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/10 23:40:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	free(arr)

int	val_av(int ac, char **av, int **a)
{
	int	idx;
	int	str_idx;

	idx = 1;
	while (idx < ac)
	{
		str_idx = 0;
		while (av[idx][str_idx])
		{
			if (ft_strchr("012345679", av[idx][str_idx]) == 0)
			{
				return (FAIL);
			}
			
			str_idx++;
		}
		idx++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	int	*a;

	if (ac <= 1)
		return (FAIL);
	a = (int *)malloc(sizeof(int) * ac - 1);
	if (val_av(ac, av, &a) == FAIL)
		return (FAIL);
	printf("val_av clear\n");
	return (SUCCESS);
}
