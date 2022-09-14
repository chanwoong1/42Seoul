/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:45:55 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 14:46:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_var *stacks)
{
	int		idx;
	int		check;
	t_node	*a;

	idx = stacks->a_size;
	a = stacks->stack_a->top->right;
	check = 0;
	while (idx > 1)
	{
		if (a->val - a->right->val < 0)
			check++;
		idx--;
		a = a->right;
	}
	if (check == stacks->a_size - 1 && stacks->a_size == stacks->list_size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ps_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	operation(char *op, t_var *stacks)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(stacks);
	else if (!ft_strcmp(op, "sb\n"))
		sb(stacks);
	else if (!ft_strcmp(op, "ss\n"))
		ss(stacks);
	else if (!ft_strcmp(op, "pa\n"))
		pa(stacks);
	else if (!ft_strcmp(op, "pb\n"))
		pb(stacks);
	else if (!ft_strcmp(op, "ra\n"))
		ra(stacks);
	else if (!ft_strcmp(op, "rb\n"))
		rb(stacks);
	else if (!ft_strcmp(op, "rr\n"))
		rr(stacks);
	else if (!ft_strcmp(op, "rra\n"))
		rra(stacks);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(stacks);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(stacks);
	else
		ps_error();
}

void	operating(t_var *stacks)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		operation(op, stacks);
		free(op);
	}
}
