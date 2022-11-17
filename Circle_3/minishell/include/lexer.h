/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:25:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/* Libft functions */
# include "./libft.h"

/* t_string header */
# include "../src/string/string.h"
# include "../src/iterator/iterator.h"
# include "../src/lexer/token.h"
# include "../src/lexer/scanner.h"

/* @ Returns t_token list.
 * @ NOTE : doesn't check synstax error!
 * */
extern t_list	*tokenize(char *line);

#endif /* LEXER_H */
