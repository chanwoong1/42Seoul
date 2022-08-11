/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:10:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/11 17:16:42 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>

# define SUCCESS	1
# define FAIL		-1

typedef struct s_stack
{
	int				 item;
	struct s_stack	*link;
} 					t_stack;

typedef struct
{
	t_stack *top;
}			t_linked_stack;

int		main(int ac, char **av);
void	val_av(int ac, char **av, t_linked_stack *a);
void	init(t_linked_stack *s);
int		is_empty(t_linked_stack *s);
void	push(t_linked_stack *s, int item);
int		pop(t_linked_stack *s);
int		peek(t_linked_stack *s);
void	free_node(t_linked_stack *head);

#endif
