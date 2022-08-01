/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:48:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/01 17:21:55 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int ft_printf(const char *format, ...);
int	is_specifier(const char sp);
int	is_printable(char **print, const char *format, va_list *ap);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, size_t n);
int	ft_print_c(char **print, va_list *ap);
int	ft_print_s(char **print, va_list *ap);
int	ft_print_p(char **print, va_list *ap);

#endif