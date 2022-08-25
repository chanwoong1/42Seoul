/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:51:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/25 11:03:43 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

#endif
