/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:10:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/18 19:53:11 by chanwjeo         ###   ########.fr       */
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
	char				**list;
	int					list_size;
	int					a_size;
	int					b_size;
}	t_var;


int		main(int ac, char **av);
void	stacking(int ac, char **av, t_var *stacks);
void	valid_stacking_args(int ac, char **av, t_var *stacks);
void	ps_error(void);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
t_node	*get_new_node(int num);
void	init_stack(t_var *var);
void	push_bottom(t_stack *stack, t_node *new_node);
void	push_top(t_stack *stack, t_node *new_node);

#endif
