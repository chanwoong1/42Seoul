/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:10:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/27 12:47:06 by chanwjeo         ###   ########.fr       */
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
void	ps_error(void);

/* utils.c */
char	*ft_strchr(const char *s, int c);
void	check_sort(t_var *stacks);
int		find_list_max(t_var *stacks);
void	indexing(t_var *stacks);
void	stacking(t_var *stacks);

/* utils2.c */
int		ft_strlen(char *s);
char	*ps_all_join(int ac, char **av);

/* split.c */
char	**ft_split(char const *s, char c);
void	free_arr(char **arr, int i);

/* validate.c */
void	validate_args(int ac, char **av, t_var *stacks);

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

/* sort.c */
void	operating(t_var *stacks);
void	sort_args(t_var *stacks);
void	sort_big_last(t_var *stacks);
void	sort_three_args(t_var *stacks);

/* sort_rotate.c */
void	get_min_rotate(t_var *stacks, int *a, int *b);
void	rotate_a(t_var *stacks, int a);
void	rotate_b(t_var *stacks, int b);
void	rotate_same(t_var *stacks, int *a, int *b);

/* sort_utils.c */
void	divide_pivot(t_var *stacks);
int		get_bigger(int a, int b, int a_loc, int b_loc);
int		get_stack_min(t_var *stacks);
int		get_stack_max(t_var *stacks);

/* set_location.c */
int		find_a_location(int num, t_var *stacks);
int		find_a_min(t_var *stacks);
int		find_a_max(t_var *stacks);
int		find_a_mid(int num, t_var *stacks);

#endif
