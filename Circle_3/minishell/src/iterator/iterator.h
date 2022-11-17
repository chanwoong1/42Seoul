/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:24:31 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/16 19:41:37 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H

# include <errno.h>
# include "../../include/libft.h"

# define EOF			(-1)
# define ERRCHAR		(0)

# define INIT_SRC_POS	(-2)

typedef struct s_iterator	t_iterator;

/* line     : the input text */
/* line_len : size of the input text */
/* curpos   : iterator position is line */
typedef struct s_iterator {
	char	*line;
	long	line_len;
	long	curpos;
	int		(*f_has_next)(t_iterator *iter);
	char	(*f_next)(t_iterator *iter);
	void	(*f_unget)(t_iterator *iter);
	char	(*f_peek)(t_iterator *iter);
	void	(*f_skip_white_space)(t_iterator *iter);
}	t_iterator;

void	init_iterator(t_iterator *iter, char *line);

int		iter_has_next(t_iterator *iter);
char	iter_next(t_iterator *iter);
void	iter_unget(t_iterator *iter);
char	iter_peek(t_iterator *iter);
void	iter_skip_white_space(t_iterator *iter);

#endif /* ITERATOR_H */
