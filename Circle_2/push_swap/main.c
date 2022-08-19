/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/19 15:16:34 by chanwjeo         ###   ########.fr       */
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
