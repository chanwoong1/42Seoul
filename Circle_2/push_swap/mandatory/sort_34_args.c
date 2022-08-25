/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_34_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:16:08 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 10:30:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_args_add_on(t_var *stacks, t_node *tmp)
{
	push_top(stacks->stack_a, tmp);
	ra(stacks);
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
		sort_three_args(stacks);
		return ;
	}
	if (stacks->stack_a->top->right->val == stacks->list_size - 1)
	{
		push_top(stacks->stack_a, tmp);
		rra(stacks);
		sort_three_args(stacks);
		return ;
	}
	push_top(stacks->stack_a, tmp);
}

void	sort_four_args(t_var *stacks)
{
	t_node	*tmp;

	while (1)
	{
		tmp = pop_top(stacks->stack_a);
		if (tmp->val == 3)
		{
			push_top(stacks->stack_a, tmp);
			pb(stacks);
			stacks->list_size--;
			sort_three_args(stacks);
			pa(stacks);
			stacks->list_size++;
			ra(stacks);
			break ;
		}
		push_top(stacks->stack_a, tmp);
		ra(stacks);
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
