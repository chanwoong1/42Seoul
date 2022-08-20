/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/20 14:29:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	sort_four_args(t_var *stacks)
{
	
}

void	operating(t_var *stacks)
{
	if (stacks->list_size == 2)
		sort_two_args(stacks);
	else if (stacks->list_size == 3)
		sort_three_args(stacks);
	else if (stacks->list_size == 4)
		sort_four_args(stacks);
}

int	main(int ac, char **av)
{
	t_var	stacks;
	t_node	*tmp;
	int		idx;

	if (ac >= 2)
	{
		init_stack(&stacks);
		validate_args(ac, av, &stacks);
		check_sort(&stacks);
		indexing(&stacks);
		stacking(&stacks);
		operating(&stacks);
	}
	// sa(&stacks);
	idx = 0;
	while (idx < (&stacks)->list_size)
	{
		tmp = pop_top((&stacks)->stack_a);
		printf("%d\n", tmp->val);
		idx++;
	}
	return (0);
}
