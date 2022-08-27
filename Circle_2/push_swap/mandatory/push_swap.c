/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/27 12:44:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_var	stacks;

	if (ac >= 2)
	{
		init_stack(&stacks);
		validate_args(ac, av, &stacks);
		check_sort(&stacks);
		indexing(&stacks);
		stacking(&stacks);
		operating(&stacks);
		exit(0);
	}
	return (0);
}
