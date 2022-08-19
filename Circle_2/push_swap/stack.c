/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:12:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/19 15:11:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	init_stack(t_var *var)
{
	var->stack_a = (t_stack *)malloc(sizeof(t_stack));
	var->stack_b = (t_stack *)malloc(sizeof(t_stack));
	var->stack_a->top = get_new_node(0);
	var->stack_a->bottom = get_new_node(0);
	var->stack_a->top->right = var->stack_a->bottom;
	var->stack_a->bottom->left = var->stack_a->top;
	var->stack_b->top = get_new_node(0);
	var->stack_b->bottom = get_new_node(0);
	var->stack_b->top->right = var->stack_b->bottom;
	var->stack_b->bottom->left = var->stack_b->top;
	var->list = (int *)malloc(sizeof(int));
	var->list_size = 0;
}

void	push_top(t_stack *stack, t_node *new_node)
{
	t_node	*top;
	t_node	*temp;

	top = stack->top;
	temp = top->right;
	top->right = new_node;
	temp->left = new_node;
	new_node->left = top;
	new_node->right = temp;
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*bottom;
	t_node	*temp;

	bottom = stack->bottom;
	temp = bottom->left;
	bottom->left = new_node;
	temp->right = new_node;
	new_node->left = temp;
	new_node->right = bottom;
}
