/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/18 19:31:58 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	ps_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

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
	push_top(stacks->stack_a, pop_top(stacks->stack_b));
}

void	pb(t_var *stacks)
{
	push_top(stacks->stack_b, pop_top(stacks->stack_a));
}

void	ra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
}

int	main(int ac, char **av)
{
	t_var	stacks;
	t_node	*tmp;

	if (ac >= 2)
	{
		init_stack(&stacks);
		valid_stacking_args(ac, av, &stacks);
	}
	sa(&stacks);
	tmp = pop_top((&stacks)->stack_a);
	while (tmp)
	{
		printf("%d\n", tmp->val);
		tmp = pop_top((&stacks)->stack_a);
	}
	return (0);
}
