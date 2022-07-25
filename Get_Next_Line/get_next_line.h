/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:50:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/25 18:05:39 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# define FAIL			0

char    *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_find(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*read_buf(int fd, char *tmp);

#endif
