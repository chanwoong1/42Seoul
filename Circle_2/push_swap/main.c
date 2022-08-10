/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/10 21:39:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	val_av(int ac, char **av)
{
	int	idx;
	int	str_idx;

	idx = 0;
	while (idx < ac)
	{
		str_idx = 0;
		while (av[idx][str_idx])
		{
			if (ft_strchr("012345679", av[idx][str_idx]) != 0)
				return (FAIL);
			str_idx++;
		}
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (val_av(ac, av) == FAIL)
		return (FAIL);
	write(1, "1", 1);
	return (SUCCESS);
}
