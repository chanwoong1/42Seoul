/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:35:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 10:32:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_var *stacks, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stacks);
			a--;
		}
		else
		{
			rra(stacks);
			a++;
		}
	}
}

void	rotate_b(t_var *stacks, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stacks);
			b--;
		}
		else
		{
			rrb(stacks);
			b++;
		}
	}
}

void	rotate_same(t_var *stacks, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stacks);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stacks);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	get_min_rotate(t_var *stacks, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			idx;
	t_node		*b_node;
	int			num;

	idx = 0;
	b_node = stacks->stack_b->top->right;
	while (idx < stacks->b_size)
	{
		num = b_node->val;
		a_location = find_a_location(num, stacks);
		if (idx >= (stacks->b_size + 1) / 2)
			b_location = (stacks->b_size - idx) * -1;
		else
			b_location = idx;
		if (idx == 0 || get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		b_node = b_node->right;
		idx++;
	}
}
