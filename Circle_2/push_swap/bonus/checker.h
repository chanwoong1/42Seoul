/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:51:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/26 12:22:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

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

/* checker_utils.c */
char	*ft_strchr(const char *s, int c);
int		find_list_max(t_var *stacks);
void	indexing(t_var *stacks);
void	stacking(t_var *stacks);

/* checker_utils2.c */
void	ps_error(void);
void	checker(t_var *stacks);
int		ft_strcmp(char *s1, char *s2);
void	operation(char *op, t_var *stacks);
void	operating(t_var *stacks);

/* validate_checker.c */
void	validate_args(int ac, char **av, t_var *stacks);

/* split.c */
char	**ft_split(char const *s, char c);

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

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
int		gnl_strlen(const char *s);
int		gnl_strchr(char *s);
char	*gnl_strjoin(char *s1, char *s2);

#endif
