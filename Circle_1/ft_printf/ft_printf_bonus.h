/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:19:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 15:09:26 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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
int		print_c(va_list *ap);
int		print_with_c(t_flag *form_sp, va_list *ap);
int		print_s(char *args);
int		print_with_s(t_flag *form_sp, va_list *ap);
int		print_p(t_flag *form_sp, char *pt);
int		print_with_p(t_flag *form_sp, va_list *ap);
int		print_id(va_list *ap);
int		print_u(t_flag *form_sp, va_list *ap);
int		print_x(unsigned int args);
int		print_xx(unsigned int args);
int		print_with_x(t_flag *form_sp, va_list *ap);
int		print_percent(va_list *ap);
int		id_args_lens(long long args);
int		p_p(char c, int n);
void	set_info(t_flag *form_sp);
void	fill_info(t_flag *form_sp, char *format, int idx);
int		id_args_lens(long long args);
int		id_hex_lens(long long args);
int		print_with_percent_add(t_flag *form_sp);
int		print_with_percent(t_flag *form_sp);
int		id_args_zero(t_flag *form_sp);
int		id_args_zero_2(t_flag *form_sp);
int		print_with_id(t_flag *form_sp, va_list *ap);
int		id_args_non_zero(t_flag *form_sp, long long args, int sign);
int		id_args_non_precision(t_flag *form_sp, long long args, int sign);
int		id_args_non_pre_non_minus(t_flag *form_sp, long long args, int sign);
int		id_args_non_p_non_m_zero(t_flag *form_sp, long long args, int sign);
int		id_args_prec_width_minus2(t_flag *form_sp, long long args, int sign);
int		id_args_prec_width_minus(t_flag *form_sp, long long args, int sign);
int		id_args_prec_width(t_flag *form_sp, long long args, int sign);
int		id_args_prec(t_flag *form_sp, long long args, int sign);
int		id_args_non_zero(t_flag *form_sp, long long args, int sign);

#endif
