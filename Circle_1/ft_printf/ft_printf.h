/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:19:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/09 14:29:40 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flag
{
	char	sp;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		prec;
}			t_flag;

int		ft_printf(const char *form, ...);
int		print_num(long long num);
int		print_with_c(t_flag *opt, va_list *ap);
int		print_with_s(t_flag *opt, va_list *ap);
int		print_p(t_flag *opt, char *pt);
int		print_with_p(t_flag *opt, va_list *ap);
int		print_u(t_flag *opt, va_list *ap);
int		print_x(unsigned int args);
int		print_xx(unsigned int args);
int		print_with_x(t_flag *opt, va_list *ap);
int		print_percent(va_list *ap);
int		id_args_lens(long long args);
int		p_p(char c, int n);
void	set_info(t_flag *opt);
void	fill_info(t_flag *opt, char *format, int idx);
int		id_args_lens(long long args);
int		id_hex_lens(long long args);
int		print_with_percent_add(t_flag *opt);
int		print_with_percent(t_flag *opt);
int		id_args_zero(t_flag *opt);
int		id_args_zero_2(t_flag *opt);
int		id_args_zero_3(t_flag *opt);
int		id_space_zero(t_flag *opt);
int		id_space_zero_2(t_flag *opt);
int		print_with_id(t_flag *opt, va_list *ap);
int		id_args_non_zero(t_flag *opt, long long args, int sign);
int		id_args_non_precision(t_flag *opt, long long args, int sign);
int		id_args_non_pre_non_minus(t_flag *opt, long long args, int sign);
int		id_args_non_p_non_m_zero(t_flag *opt, long long args, int sign);
int		id_args_prec_width_minus2(t_flag *opt, long long args, int sign);
int		id_args_prec_width_minus(t_flag *opt, long long args, int sign);
int		id_args_prec_width(t_flag *opt, long long args, int sign);
int		id_args_prec(t_flag *opt, long long args, int sign);
int		id_args_non_zero(t_flag *opt, long long args, int sign);
int		in_hex_1(t_flag *opt, unsigned int args, int hashtag, int len_args);
int		in_hex_2(t_flag *opt, unsigned int args, int hashtag, int len_args);
int		in_hex_3(t_flag *opt, unsigned int args, int hashtag);
int		in_hex_4(t_flag *opt, unsigned int args, int hashtag, int len_args);
int		in_hex_5(t_flag *opt, unsigned int args, int hashtag, int len_args);

#endif
