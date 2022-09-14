/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:06:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/27 12:05:46 by chanwjeo         ###   ########.fr       */
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
	new_node = NULL;
	while (idx < stacks->list_size)
	{
		new_node = get_new_node(stacks->list[idx] + 1);
		if (!new_node)
			ps_error();
		push_bottom(stacks->stack_a, new_node);
		idx++;
		free(new_node);
		new_node = NULL;
	}
	stacks->a_size = stacks->list_size;
	stacks->max_size = stacks->list_size;
}
