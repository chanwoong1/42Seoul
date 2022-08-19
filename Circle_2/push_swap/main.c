/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/20 00:32:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	operating(t_var *stacks)
{
	
}

void	stacking(t_var *stacks)
{
	t_node	*new_node;
	int		idx;

	idx = 0;
	while (idx < stacks->list_size)
	{
		new_node = get_new_node(stacks->list[idx]);
		push_top(stacks->stack_a, new_node);
		idx++;
	}
	stacks->a_size = stacks->list_size;
}

int	main(int ac, char **av)
{
	t_var	stacks;
	t_node	*tmp;

	if (ac >= 2)
	{
		init_stack(&stacks);
		validate_args(ac, av, &stacks);
		check_sort(&stacks);
		indexing(&stacks);
		stacking(&stacks);
		operating(&stacks);
	}
	// rra(&stacks);
	tmp = pop_top((&stacks)->stack_a);
	while (tmp)
	{
		printf("%d\n", tmp->val);
		tmp = pop_top((&stacks)->stack_a);
	}
	return (0);
}
