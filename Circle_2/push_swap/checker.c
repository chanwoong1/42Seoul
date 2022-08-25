/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:49:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 10:51:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_var *stacks)
{
	int	idx;
	int	check;

	idx = stacks->list_size;
	check = 0;
	while (idx > 1)
	{
		if (stacks->list[idx - 1] - stacks->list[idx - 2] > 0)
			check++;
		idx--;
	}
	if (check == stacks->list_size - 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ps_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_var	stacks;

	if (ac >= 2)
	{
		init_stack(&stacks);
		validate_args(ac, av, &stacks);
		check_sort(&stacks);
		indexing(&stacks);
		stacking(&stacks);
		operating(&stacks);
		checker(&stacks);
		exit(0);
	}
	ps_error();
	return (0);
}
