/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:51:14 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

bool	is_type_redir_arg(t_list *target_next)
{
	t_token	*tok;

	tok = target_next->content;
	if (tok->type == E_TYPE_REDIR_ARG \
			|| tok->type == E_TYPE_REDIR_ARG_HEREDOC_QUOTED)
		return (true);
	else
		return (false);
}
