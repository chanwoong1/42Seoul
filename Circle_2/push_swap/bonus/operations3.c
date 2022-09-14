/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:20:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 11:20:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
}

void	rrb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
}

void	rrr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
}
