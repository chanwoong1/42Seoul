/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "helper.h"
#include "../../include/lexer.h"

const char	*get_token_type(t_token_type type)
{
	static const char	*type_table[14];

	type_table[0] = "E_TYPE_DOUBLE_AMPERSAND";
	type_table[1] = "E_TYPE_DOUBLE_PIPE";
	type_table[2] = "E_TYPE_PIPE";
	type_table[3] = "E_TYPE_BRACKET";
	type_table[4] = "E_TYPE_SIMPLE_CMD";
	type_table[5] = "E_TYPE_REDIR_GREATER";
	type_table[6] = "E_TYPE_REDIR_LESS";
	type_table[7] = "E_TYPE_REDIR_APPEND";
	type_table[8] = "E_TYPE_REDIR_HEREDOC";
	type_table[9] = "E_TYPE_REDIR_ARG";
	type_table[10] = "E_TYPE_WHITESPACE";
	type_table[11] = "E_TYPE_DEFAULT";
	type_table[12] = "E_TYPE_REDIRECT";
	type_table[13] = "E_TYPE_REDIR_ARG_HEREDOC_QUOTED";
	return (type_table[type]);
}

void	print_tokens(t_list *tokens)
{
	t_list	*tmp;
	t_token	*tok;

	tmp = tokens;
	if (tmp == NULL)
		printf("No data\n");
	while (tmp != NULL)
	{
		tok = tmp->content;
		printf("\033[93m%20s $\033[0m", get_token_type(tok->type));
		printf("%s\n", tok->str->text);
		tmp = tmp->next;
	}
}

void	print_tree_node(t_list *token)
{
	t_list	*tmp;
	t_token	*tok;

	if (token == NULL)
		printf("\033[90m[null]\033[0m");
	tmp = token;
	while (tmp != NULL)
	{
		tok = tmp->content;
		printf("\033[92m[%s]\033[0m", tok->str->text);
		tmp = tmp->next;
	}
}
