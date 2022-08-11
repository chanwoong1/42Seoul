/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/11 19:32:24 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	free_node(t_linked_stack *head)
{
	while (!is_empty(head))
		pop(head);
}

void	stacking(int ac, char **av, t_linked_stack *a)
{
	int	idx;
	int	s_idx;

	idx = 1;
	while (idx < ac)
	{
		s_idx = 0;
		while (av[idx][s_idx])
		{
			if (ft_strchr("-0123456789", av[idx][s_idx]) == 0)
			{
				free_node(a);
				return ;
			}
			s_idx++;
		}
		push(a, ft_atoi(av[idx]));
		idx++;
	}
}

void free_arr(char **arr)
{
	int	arr_size;

	arr_size = 0;
	while (arr[arr_size] != 0)
		arr_size++;
	while (arr_size > 0)
	{
		free(arr[arr_size - 1]);
		arr_size--;
	}
	free(arr);
}

int	ps_arrlen(char **arr)
{
	int	size;

	size = 0;
	while (arr[size] != 0)
		size++;
	return (size);
}

void	ps_arrcat(char ***dest, char **src)
{
	int	idx;
	int	s_idx;
	int	ss_idx;

	idx = 0;
	s_idx = 0;
	while (*dest[idx] != 0)
		idx++;
	while (src[s_idx] != 0)
	{
		if (!(*dest[idx] = (char *)malloc(sizeof(ft_strlen(src[s_idx] + 1)))))
		{
			*dest[0] = 0;
			return ;
		}
		ss_idx = -1;
		while (src[s_idx][++ss_idx])
			*dest[idx][ss_idx] = src[s_idx][ss_idx];
		*dest[idx][ss_idx] = '\0';
		s_idx++;
		idx++;
	}
	*dest[idx] = 0;
}

char	**ps_arrjoin(char **arr1, char **arr2)
{
	char	**copy;
	int		arr1_size;
	int		arr2_size;

	arr1_size = ps_arrlen(arr1);
	arr2_size = ps_arrlen(arr2);
	copy = (char **)malloc(sizeof(char *) * (arr1_size + arr2_size + 1));
	if (!copy)
		return (0);
	copy[0] = 0;
	ps_arrcat(&copy, arr1);
	if (copy[0] == 0)
		return (0);
	ps_arrcat(&copy, arr2);
	return (copy);
}

char	**val_av(int ac, char **av)
{
	int		idx;
	char	**tmp;
	char	**ret_av;
	char	**tmp_av;

	idx = 1;
	if (!(ret_av = (char **)malloc(sizeof(char *))))
		return (NULL);
	ret_av[0] = 0;
	while (idx < ac)
	{
		tmp = ft_split(av[idx], ' ');
		if (tmp[0] == 0)
			return (NULL);
		if (!(tmp_av = ps_arrjoin(ret_av, tmp)))
			return (NULL);
		free_arr(ret_av);
		ret_av = tmp_av;
		idx++;
	}
	return (ret_av);
}

int	main(int ac, char **av)
{
	t_linked_stack	a;
	char			**v_av;

	if (ac <= 1)
		return (FAIL);
	init(&a);
	v_av = val_av(ac, av);
	stacking(ac, av, &a);
	printf("%d\n", pop(&a));
	printf("%d\n", pop(&a));
	printf("%d\n", pop(&a));
	printf("%d\n", is_empty(&a));
}
