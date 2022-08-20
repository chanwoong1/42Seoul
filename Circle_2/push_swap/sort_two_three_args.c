/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:16:08 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/20 14:17:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort_two_args(t_var *stacks)
{
	sa(stacks);
	write(1, "sa\n", 3);
}

void	sort_three_args_add_on(t_var *stacks, t_node *tmp)
{
	push_top(stacks->stack_a, tmp);
	ra(stacks);
	write(1, "ra\n", 3);
	sort_three_args(stacks);
}

void	sort_three_args(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	if (tmp->val == stacks->list_size - 1)
	{
		sort_three_args_add_on(stacks, tmp);
		return ;
	}
	if (tmp->val == stacks->list_size - 2)
	{
		push_top(stacks->stack_a, tmp);
		sa(stacks);
		write(1, "sa\n", 3);
		sort_three_args(stacks);
		return ;
	}
	if (stacks->stack_a->top->right->val == stacks->list_size - 1)
	{
		push_top(stacks->stack_a, tmp);
		rra(stacks);
		write(1, "rra\n", 4);
		sort_three_args(stacks);
		return ;
	}
	push_top(stacks->stack_a, tmp);
}
