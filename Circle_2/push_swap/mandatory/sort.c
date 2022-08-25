/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:05:56 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 10:40:04 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operating(t_var *stacks)
{
	if (stacks->list_size == 2)
		sa(stacks);
	else if (stacks->list_size == 3)
		sort_three_args(stacks);
	else if (stacks->list_size == 4)
		sort_four_args(stacks);
	else
		sort_args(stacks);
}

void	sort_args(t_var *stacks)
{
	int	a;
	int	b;

	divide_pivot(stacks);
	while (stacks->a_size > 3)
		pb(stacks);
	if (stacks->a_size == 2)
	{
		if (stacks->stack_a->top->right->val > \
			stacks->stack_a->top->right->right->val)
			sa(stacks);
	}
	if (stacks->a_size == 3)
		sort_args_for_astack(stacks);
	while (stacks->b_size)
	{
		a = 0;
		b = 0;
		get_min_rotate(stacks, &a, &b);
		rotate_same(stacks, &a, &b);
		rotate_a(stacks, a);
		rotate_b(stacks, b);
		pa(stacks);
	}
	sort_big_last(stacks);
}

void	sort_big_last(t_var *stacks)
{
	int	min_location;

	min_location = find_a_min(stacks);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(stacks);
			min_location--;
		}
		else
		{
			rra(stacks);
			min_location++;
		}
	}
}
