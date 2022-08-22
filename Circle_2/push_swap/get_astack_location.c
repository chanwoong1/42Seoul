/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_astack_location.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 00:51:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/22 10:56:34 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_a_location_min(t_var *stacks)
{
	int			ret;
	int			index;
	int			tmp;
	t_node		*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	index = get_stack_min(stacks);
	while (stack_a)
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

int	set_a_location_max(t_var *stacks)
{
	int			ret;
	int			index;
	int			tmp;
	t_node		*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	index = get_stack_max(stacks);
	while (stack_a)
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

int	set_a_location_mid(int num, t_var *stacks)
{
	t_node		*stack_a;
	int			ret;

	stack_a = stacks->stack_a->top->right;
	ret = 1;
	while (stack_a->right)
	{
		if (num > stack_a->val && num < stack_a->right->val)
			break ;
		ret++;
		stack_a = stack_a->right;
	}
	if (ret >= (stacks->a_size + 1) / 2)
		ret = (stacks->a_size - ret) * -1;
	return (ret);
}

int	set_a_location(int num, t_var *stacks)
{
	int	ret;

	if (num < get_stack_min(stacks))
		ret = set_a_location_min(stacks);
	else if (num > get_stack_max(stacks))
		ret = set_a_location_max(stacks);
	else
		ret = set_a_location_mid(num, stacks);
	return (ret);
}

void	get_min_rotate(t_var *stacks, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			idx;
	t_node		*b_node;
	int			num;

	idx = 0;
	b_node = stacks->stack_b->top->right;
	while (idx < stacks->b_size)
	{
		num = b_node->val;
		a_location = set_a_location(num, stacks);
		if (idx >= (stacks->b_size + 1) / 2)
			b_location = (stacks->b_size - idx) * -1;
		else
			b_location = idx;
		if (idx == 0 || ft_get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		b_node = b_node->right;
		idx++;
	}
}
