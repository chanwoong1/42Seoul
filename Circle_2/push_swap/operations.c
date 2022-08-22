/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:13:13 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/22 10:56:34 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stacks->stack_a);
	tmp2 = pop_top(stacks->stack_a);
	push_top(stacks->stack_a, tmp1);
	push_top(stacks->stack_a, tmp2);
	write(1, "sa\n", 3);
}

void	sb(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stacks->stack_b);
	tmp2 = pop_top(stacks->stack_b);
	push_top(stacks->stack_b, tmp1);
	push_top(stacks->stack_b, tmp2);
	write(1, "sb\n", 3);
}

void	ss(t_var *stacks)
{
	sa(stacks);
	sb(stacks);
	write(1, "ss\n", 3);
}

void	pa(t_var *stacks)
{
	push_top(stacks->stack_a, pop_top(stacks->stack_b));
	stacks->a_size++;
	stacks->b_size--;
	write(1, "pa\n", 3);
}

void	pb(t_var *stacks)
{
	push_top(stacks->stack_b, pop_top(stacks->stack_a));
	stacks->a_size--;
	stacks->b_size++;
	write(1, "pb\n", 3);
}
