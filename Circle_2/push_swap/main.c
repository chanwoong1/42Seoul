/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/11 17:22:08 by chanwjeo         ###   ########.fr       */
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

void	val_av(int ac, char **av, t_linked_stack *a)
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

int	main(int ac, char **av)
{
	t_linked_stack	a;

	if (ac <= 1)
		return (FAIL);
	init(&a);
	val_av(ac, av, &a);
	printf("%d\n", pop(&a));
	printf("%d\n", pop(&a));
	printf("%d\n", pop(&a));
	printf("%d\n", is_empty(&a));
}

// int	main(int ac, char **av)
// {
// 	int		*a;
	
// 	if (ac <= 1)
// 		return (FAIL);
// 	printf("ac : %d\n", ac);
// 	if (!(a = (int *)malloc(sizeof(int) * (ac - 1))))
// 		return (FAIL);
// 	if (val_av(ac, av, &a) == FAIL)
// 	{
// 		free(a);
// 		return (FAIL);
// 	}
// 	printf("val_av clear\n");
// 	return (SUCCESS);
// }
