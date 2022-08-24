/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/24 18:36:01 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

void	operating(t_var *stacks)
{
	if (stacks->list_size == 2)
		sa(stacks);
	else if (stacks->list_size == 3)
		sort_three_args(stacks);
	else if (stacks->list_size == 4)
		sort_four_args(stacks);
	else
		sort_args(stacks);
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
		// print_stack(&stacks);
		exit(0);
	}
	ps_error();
	return (0);
}

void	print_stack(t_var *stacks)
{
	t_node	*tmpa;
	t_node	*tmpb;
	int		idx;
	int		idx2;

	printf("\n\nstacks\n| ----- |\n");
	idx = 0;
	if (stacks->a_size < stacks->b_size)
		while (++idx < stacks->list_size - stacks->b_size + 1)
			printf("|       | %d\n", idx);
	else
	while (++idx < stacks->list_size - stacks->a_size)
		printf("|       | %d\n", idx);
	if (stacks->a_size < stacks->b_size)
		while (idx < stacks->list_size - stacks->a_size + 1)
		{
			tmpb = pop_top(stacks->stack_b);
			printf("|     %d | %d\n", tmpb->val, idx);
			idx++;
		}
	else
		while (idx < stacks->list_size - stacks->b_size + 1)
		{
			tmpa = pop_top(stacks->stack_a);
			printf("| %d     | %d\n", tmpa->val, idx);
			idx++;
		}
	idx2 = 0;
	if (stacks->a_size < stacks->b_size)
		while (idx2 < stacks->a_size)
		{
			tmpa = pop_top(stacks->stack_a);
			tmpb = pop_top(stacks->stack_b);
			printf("| %d   %d | %d\n", tmpa->val, tmpb->val, idx2 + idx + 1);
			idx2++;
		}
	else
		while (idx2 < stacks->b_size)
		{
			tmpa = pop_top(stacks->stack_a);
			tmpb = pop_top(stacks->stack_b);
			printf("| %d   %d | %d\n", tmpa->val, tmpb->val, idx2 + idx + 1);
			idx2++;
		}
	printf("| ----- |\n| A   B | idx\n");
}
