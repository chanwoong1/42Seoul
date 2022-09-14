/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:10:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 11:20:08 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*get_new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->val = num;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*top;
	t_node	*temp;

	top = stack->top;
	if (top->right == stack->bottom)
		return (0);
	temp = top->right;
	temp->right->left = top;
	top->right = temp->right;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*bottom;
	t_node	*temp;

	bottom = stack->bottom;
	if (bottom->left == stack->top)
		return (0);
	temp = bottom->left;
	temp->left->right = bottom;
	bottom->left = temp->left;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}
