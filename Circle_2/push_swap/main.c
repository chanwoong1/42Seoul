/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/11 18:52:49 by chanwjeo         ###   ########.fr       */
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

char	**ps_arrjoin(char **arr1, char **arr2)
{
	
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
		tmp_av = ps_arrjoin(ret_av, tmp);
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
