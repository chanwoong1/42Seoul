/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 00:51:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 10:44:17 by chanwjeo         ###   ########.fr       */
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

int	get_bigger(int a, int b, int a_loc, int b_loc)
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
