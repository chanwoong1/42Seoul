/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:22:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TREE_H
# define PARSE_TREE_H

# include "../libft/include/libft.h"
# include "../lexer/token.h"

typedef struct s_tree	t_tree;

/* NOTE 
 *      (1) if is_pipeline is true, then do fork() 
 *      (2) if pipe's last cmd, then do special handling 
 **/

typedef struct s_tree {
	t_list	*token;
	t_list	*redirection;
	int		is_pipeline;
	int		is_last_pipe_cmd;
	t_tree	*left;
	t_tree	*right;
}	t_tree;

t_tree	*parse(t_list *tokens);
t_tree	*parse_to_tree_recur(t_list *tokens, int *flag);
t_list	*collect_redirection_node(t_list *tokens);
void	ft_lst_pop_one(t_list **node, t_list *pop_target);
t_list	*ft_lst_get_prev_node(t_list *node, t_list *target);
t_list	*find_top_priority_token(t_list *tokens);
t_list	*find_target_token(t_list *tokens, t_token_type _type);
t_tree	*new_tree_node(void);
bool	is_type_redir_arg(t_list *target_next);

#endif /* PARSE_H */
