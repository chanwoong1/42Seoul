/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:50:22 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/26 18:16:19 by chanwjeo         ###   ########.fr       */
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
size_t	ft_len_or_find(char *str, int flag);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strcat(char *dest, char *src);
char	*read_buf(int fd, char **tmp);
void	*ft_calloc(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*read_line(char *buf, char **tmp);

#endif
