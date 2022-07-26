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
#  define BUFFER_SIZE   1024
# endif

char	*get_next_line(int fd);
int		ft_strchr(char *s);
char	*read_buf(int fd, char **backup, char *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1, int size);
char	*read_line(char **backup, char *buf);
int		ft_strlen(const char *s);

#endif
