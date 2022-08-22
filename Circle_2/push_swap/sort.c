/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:05:56 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/22 11:37:17 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_pivot(t_var *stacks)
{
	t_node	*tmp;
	int		times;
	int		p1;
	int		p2;

	p1 = stacks->max_size / 3;
	p2 = (stacks->max_size / 3) * 2;
	times = 0;
	while (times < stacks->max_size)
	{
		tmp = pop_top(stacks->stack_a);
		if (tmp->val < p2)
		{
			push_top(stacks->stack_a, tmp);
			pb(stacks);
			if (tmp->val < p1)
				rb(stacks);
		}
		else
		{
			push_top(stacks->stack_a, tmp);
			ra(stacks);
		}
		times++;
	}
}

void	sort_args_for_astack(t_var *stacks)
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

int	get_stack_min(t_var *stacks)
{
	int		ret;
	int		times;
	t_node	*stack;

	stack = stacks->stack_a->top->right;
	ret = stack->val;
	times = 0;
	while (times < stacks->a_size - 1)
	{
		if (ret > stack->right->val)
			ret = stack->right->val;
		stack = stack->right;
		times++;
	}
	return (ret);
}

int	get_stack_max(t_var *stacks)
{
	int		ret;
	int		times;
	t_node	*stack;

	stack = stacks->stack_a->top->right;
	ret = stack->val;
	times = 0;
	while (times < stacks->a_size - 1)
	{
		if (ret < stack->right->val)
			ret = stack->right->val;
		stack = stack->right;
		times++;
	}
	return (ret);
}

void	ft_rotate_same(t_var *stacks, int *a, int *b)
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
