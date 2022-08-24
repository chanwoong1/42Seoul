/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:35:41 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 01:08:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_sort_big_last(t_var *stacks)
{
	int	min_location;

	min_location = set_a_location_min(stacks);
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

int	ft_get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	ft_rotate_a(t_var *stacks, int a)
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

void	ft_rotate_b(t_var *stacks, int b)
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
		// printf("stacks->b_size : %d\n", stacks->b_size);
		a = 0;
		b = 0;
		get_min_rotate(stacks, &a, &b);
		// printf("get_min_rotate clear\n");
		ft_rotate_same(stacks, &a, &b);
		// printf("ft_rotate_same clear\n");
		ft_rotate_a(stacks, a);
		// printf("ft_rotate_a clear\n");
		ft_rotate_b(stacks, b);
		// printf("ft_rotate_b clear\n");
		pa(stacks);
	}
	ft_sort_big_last(stacks);
}
