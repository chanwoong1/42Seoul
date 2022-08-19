/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/19 20:32:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_var	stacks;
	t_node	*tmp;

	if (ac >= 2)
	{
		init_stack(&stacks);
		valid_stacking_args(ac, av, &stacks);
		check_sort(&stacks);
		indexing(&stacks);
	}
	// rra(&stacks);
	tmp = pop_top((&stacks)->stack_a);
	while (tmp)
	{
		printf("%d\n", tmp->val);
		tmp = pop_top((&stacks)->stack_a);
	}
	return (0);
}
