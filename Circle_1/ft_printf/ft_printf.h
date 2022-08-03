/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:14:27 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/03 13:08:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_c(va_list ap);
int		print_s(va_list ap);
int		print_p(va_list ap);
int		print_id(va_list ap);
int		print_u(va_list ap);
int		print_x(va_list ap);
int		print_xx(va_list ap);
int		print_percent(va_list ap);

#endif