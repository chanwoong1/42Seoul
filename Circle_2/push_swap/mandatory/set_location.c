/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:22:09 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 10:27:06 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_min(t_var *stacks)
{
	int			ret;
	int			index;
	int			tmp;
	t_node		*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	index = get_stack_min(stacks);
	while (ret < stacks->a_size)
	{
		tmp = stack_a->val;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->right;
	}
	if (ret >= (stacks->a_size + 1) / 2)
		ret = (stacks->a_size - ret) * -1;
	return (ret);
}

int	find_a_max(t_var *stacks)
{
	int			ret;
	int			index;
	int			tmp;
	t_node		*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	index = get_stack_max(stacks);
	while (ret < stacks->a_size)
	{
		tmp = stack_a->val;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->right;
	}
	ret++;
	if (ret >= (stacks->a_size + 1) / 2)
		ret = (stacks->a_size - ret) * -1;
	return (ret);
}

int	find_a_mid(int num, t_var *stacks)
{
	t_node		*stack_a;
	int			ret;
	int			idx;

	stack_a = stacks->stack_a->top->right;
	ret = 1;
	idx = 0;
	while (idx < stacks->a_size)
	{
		if (stack_a->right->val == 0)
			return (0);
		if (num > stack_a->val && num < stack_a->right->val)
			break ;
		ret++;
		stack_a = stack_a->right;
		idx++;
	}
	if (ret >= (stacks->a_size + 1) / 2)
		ret = (stacks->a_size - ret) * -1;
	return (ret);
}

int	find_a_location(int num, t_var *stacks)
{
	int	ret;

	if (num < get_stack_min(stacks))
		ret = find_a_min(stacks);
	else if (num > get_stack_max(stacks))
		ret = find_a_max(stacks);
	else
		ret = find_a_mid(num, stacks);
	return (ret);
}
