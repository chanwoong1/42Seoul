/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:10:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/19 20:33:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	int				val;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_lists
{
	struct s_node	*top;
}	t_lists;

typedef struct s_var
{
	int					max_size;
	int					*pivot_arr;
	struct s_stack		*stack_a;
	struct s_stack		*stack_b;
	int					*list;
	int					list_size;
	int					a_size;
	int					b_size;
}	t_var;

/* main.c */
int		main(int ac, char **av);

/* utils.c */
void	ps_error(void);
void	check_sort(t_var *stacks);
int		find_list_max(t_var *stacks);
void	indexing(t_var	*stacks);

/* stacking.c */
void	valid_stacking_args(int ac, char **av, t_var *stacks);

/* stack.c */
void	init_stack(t_var *var);
void	push_top(t_stack *stack, t_node *new_node);
void	push_bottom(t_stack *stack, t_node *new_node);

/* stack2.c */
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
t_node	*get_new_node(int num);

/* operations.c */
void	sa(t_var *stacks);
void	sb(t_var *stacks);
void	ss(t_var *stacks);
void	pa(t_var *stacks);
void	pb(t_var *stacks);

/* operations2.c */
void	ra(t_var *stacks);
void	rb(t_var *stacks);
void	rr(t_var *stacks);

/* operations3.c */
void	rra(t_var *stacks);
void	rrb(t_var *stacks);
void	rrr(t_var *stacks);

#endif
