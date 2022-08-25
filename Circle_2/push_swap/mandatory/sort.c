/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:05:56 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 15:09:25 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operating(t_var *stacks)
{
	if (stacks->list_size == 2)
		sa(stacks);
	else if (stacks->list_size == 3)
		sort_three_args(stacks);
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
		sort_three_args(stacks);
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

void	sort_three_args(t_var *stacks)
{
	int	top;
	int	mid;
	int	bot;

	top = stacks->stack_a->top->right->val;
	mid = stacks->stack_a->top->right->right->val;
	bot = stacks->stack_a->top->right->right->right->val;
	if (top > mid && mid > bot && top > bot)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(stacks);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(stacks);
	else if (mid > top && mid > bot && top > bot)
		rra(stacks);
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
