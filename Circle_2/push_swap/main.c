/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/22 01:22:45 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	ft_sort_big_last(t_var *stacks)
{
	// int	min;
	int	min_location;

	// min = get_stack_min(stacks->stack_a->top->right);
	min_location = set_a_location_min(stacks);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(stacks);
			min_location--;
		}
		else
		{
			rra(stacks);
			min_location++;
		}
	}
}

int	ft_get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	ft_rotate_a(t_var *stacks, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stacks);
			a--;
		}
		else
		{
			rra(stacks);
			a++;
		}
	}
}

void	ft_rotate_b(t_var *stacks, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stacks);
			b--;
		}
		else
		{
			rrb(stacks);
			b++;
		}
	}
}

void	sort_args(t_var *stacks)
{
	int	a;
	int	b;

	divide_pivot(stacks);
	while (stacks->a_size > 3)
		pb(stacks);
	if (stacks->a_size == 2)
		if (stacks->stack_a->top->right->val > \
			stacks->stack_a->top->right->right->val)
			sa(stacks);
	sort_args_for_astack(stacks);
	while (stacks->b_size)
	{
		a = 0;
		b = 0;
		get_min_rotate(stacks, &a, &b);
		ft_rotate_same(stacks, &a, &b);
		ft_rotate_a(stacks, a);
		ft_rotate_b(stacks, b);
		pa(stacks);
	}
	ft_sort_big_last(stacks);
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

void	print_stack(t_var *stacks)
{
	t_node	*tmpa;
	t_node	*tmpb;
	int		idx;
	int		idx2;

	printf("\n\nstacks\n| ----- |\n");
	idx = -1;
	if (stacks->a_size < stacks->b_size)
		while (++idx < stacks->list_size - stacks->b_size)
			printf("|       | %d\n", idx);
	else
	while (++idx < stacks->list_size - stacks->a_size)
		printf("|       | %d\n", idx);
	if (stacks->a_size < stacks->b_size)
		while (idx < stacks->list_size - stacks->a_size)
		{
			tmpb = pop_top(stacks->stack_b);
			printf("|     %d | %d\n", tmpb->val, idx);
			idx++;
		}
	else
		while (idx < stacks->list_size - stacks->b_size)
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
			printf("| %d   %d | %d\n", tmpa->val, tmpb->val, idx2 + idx);
			idx2++;
		}
	else
		while (idx2 < stacks->b_size)
		{
			tmpa = pop_top(stacks->stack_a);
			tmpb = pop_top(stacks->stack_b);
			printf("| %d   %d | %d\n", tmpa->val, tmpb->val, idx2 + idx);
			idx2++;
		}
	printf("| ----- |\n| A   B | idx\n");
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
		print_stack(&stacks);
		exit(0);
	}
	exit(1);
	return (0);
}
