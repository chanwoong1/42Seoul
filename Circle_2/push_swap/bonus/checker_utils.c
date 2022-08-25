/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:06:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 11:12:06 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	check_sort(t_var *stacks)
{
	int	idx;
	int	check;

	idx = stacks->list_size;
	check = 0;
	while (idx > 1)
	{
		if (stacks->list[idx - 1] - stacks->list[idx - 2] > 0)
			check++;
		idx--;
	}
	if (check == stacks->list_size - 1)
		ps_error();
}

int	find_list_max(t_var *stacks)
{
	int	max;
	int	idx;

	max = -2147483648;
	idx = 0;
	while (idx < stacks->list_size)
	{
		if (max < stacks->list[idx])
			max = stacks->list[idx];
		idx++;
	}
	idx = 0;
	while (idx < stacks->list_size)
	{
		if (max == stacks->list[idx])
		{
			stacks->list[idx] = -2147483648;
			return (idx);
		}
		idx++;
	}
	return (-1);
}

void	indexing(t_var *stacks)
{
	int	*idx_list;
	int	idx;
	int	max_idx;

	idx_list = (int *)malloc(sizeof(int) * stacks->list_size);
	idx = stacks->list_size - 1;
	while (idx >= 0)
	{
		max_idx = find_list_max(stacks);
		idx_list[max_idx] = idx;
		idx--;
	}
	free(stacks->list);
	stacks->list = idx_list;
}

void	stacking(t_var *stacks)
{
	t_node	*new_node;
	int		idx;

	idx = 0;
	while (idx < stacks->list_size)
	{
		new_node = get_new_node(stacks->list[idx] + 1);
		push_bottom(stacks->stack_a, new_node);
		idx++;
	}
	stacks->a_size = stacks->list_size;
	stacks->max_size = stacks->list_size;
}
