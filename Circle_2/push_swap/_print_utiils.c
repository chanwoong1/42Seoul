/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_utiils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:15:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 09:18:22 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 제출 파일 아님 */

#include "push_swap.h"
#include <stdio.h>

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

void	print_a_stack(t_var *stacks)
{
	int	idx;
	t_node	*a;

	ra(stacks);
	idx = 0;
	a = stacks->stack_a->top;
	while (idx < stacks->a_size + 2)
	{
		printf("%d\n",a->val);
		a = a->right;
		idx++;
	}
	printf("\n\n");
	idx = 0;
	a = stacks->stack_a->bottom->left;
	while (idx < stacks->a_size + 1)
	{
		printf("%d\n",a->val);
		a = a->left;
		idx++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	if (fd < 0)
		return ;
	ln = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	if (ln < 10)
	{
		c = ln + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		c = ln % 10 + '0';
		write(fd, &c, 1);
	}	
}
