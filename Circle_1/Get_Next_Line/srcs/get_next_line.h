/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:05:08 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/27 07:21:30 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
int		ft_strlen(const char *s);
int		ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
