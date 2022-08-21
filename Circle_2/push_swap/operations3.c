/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:20:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/21 13:12:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
	write(1, "rrb\n", 4);
}

void	rrr(t_var *stacks)
{
	rra(stacks);
	rrb(stacks);
	write(1, "rrr\n", 4);
}
