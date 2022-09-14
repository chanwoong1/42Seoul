/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:13:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 11:20:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stacks->stack_a);
	tmp2 = pop_top(stacks->stack_a);
	push_top(stacks->stack_a, tmp1);
	push_top(stacks->stack_a, tmp2);
}

void	sb(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stacks->stack_b);
	tmp2 = pop_top(stacks->stack_b);
	push_top(stacks->stack_b, tmp1);
	push_top(stacks->stack_b, tmp2);
}

void	ss(t_var *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_var *stacks)
{
	if (stacks->stack_b->top->right->val != 0)
	{
		push_top(stacks->stack_a, pop_top(stacks->stack_b));
		stacks->a_size++;
		stacks->b_size--;
	}
}

void	pb(t_var *stacks)
{
	if (stacks->stack_a->top->right->val != 0)
	{
		push_top(stacks->stack_b, pop_top(stacks->stack_a));
		stacks->a_size--;
		stacks->b_size++;
	}
}
