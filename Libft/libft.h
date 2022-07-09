/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:35:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/09 15:01:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
size_t  ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
size_t  ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);
int		strncmp(const char *s1, const char *s2, size_t n);