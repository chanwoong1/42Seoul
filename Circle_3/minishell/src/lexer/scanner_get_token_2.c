/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_get_token_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:01:20 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"

void	get_pipe(t_token *tok, t_scanner *scan)
{
	tok->f_push_back(tok, scan->f_next(scan));
	tok->type = E_TYPE_PIPE;
	if (scan->f_peek(scan) == '|')
	{
		tok->f_push_back(tok, scan->f_next(scan));
		tok->type = E_TYPE_DOUBLE_PIPE;
	}
}

void	get_ampersand(t_token *tok, t_scanner *scan)
{
	tok->f_push_back(tok, scan->f_next(scan));
	tok->type = E_TYPE_AMPERSAND;
	if (scan->f_peek(scan) == '&')
	{
		tok->f_push_back(tok, scan->f_next(scan));
		tok->type = E_TYPE_DOUBLE_AMPERSAND;
	}
}

void	get_redirection(t_token *tok, t_scanner *scan)
{
	char	c;

	tok->f_push_back(tok, scan->f_next(scan));
	tok->type = E_TYPE_REDIRECT;
	c = scan->f_peek(scan);
	if (c == '<' || c == '>')
		tok->f_push_back(tok, scan->f_next(scan));
}

void	get_double_quote(t_token *tok, t_scanner *scan)
{
	char	c;

	tok->f_push_back(tok, scan->f_next(scan));
	while (scan->f_has_next(scan))
	{
		c = scan->f_peek(scan);
		if (c == '\"')
			break ;
		tok->f_push_back(tok, scan->f_next(scan));
	}
	tok->f_push_back(tok, scan->f_next(scan));
}

void	get_single_quote(t_token *tok, t_scanner *scan)
{
	char	c;

	tok->f_push_back(tok, scan->f_next(scan));
	while (scan->f_has_next(scan))
	{
		c = scan->f_peek(scan);
		if (c == '\'')
			break ;
		tok->f_push_back(tok, scan->f_next(scan));
	}
	tok->f_push_back(tok, scan->f_next(scan));
}
