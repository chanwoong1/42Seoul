/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:18:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/05 12:47:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>

int	print_form_sp(t_flag *form_sp, va_list ap)
{
	int	r_c;

	r_c = 0;
	if (form_sp->sp == '%')
		r_c = print_with_percent(form_sp);
	if (form_sp->sp == 'i' || form_sp->sp == 'd')
		r_c = print_with_id(form_sp, ap);
	if (form_sp->sp == 'u')
		r_c = print_u(form_sp, ap);
	if (form_sp->sp == 'x' || form_sp->sp == 'X')
		r_c = print_with_x(form_sp, ap);
	if (form_sp->sp == 'p')
		r_c = print_with_p(form_sp, ap);
	if (form_sp->sp == 'c')
		r_c = print_c(ap);
	return (r_c);
}

int	is_printf_flag(char *format, int *idx, va_list ap)
{
	t_flag	*form_sp;
	int		r_c;

	r_c = 0;
	(*idx)++;
	form_sp = malloc(sizeof(t_flag));
	set_info(form_sp);
	while (ft_strchr("-0.# +123456789", format[*idx]))
	{
		fill_info(form_sp, format, *idx);
		(*idx)++;
	}
	if (ft_strchr("cspdiuxX%", format[*idx]))
	{
		form_sp->sp = format[*idx];
		r_c = print_form_sp(form_sp, ap);
	}
	free(form_sp);
	return (r_c);
}

int	count_printf(char *form, va_list ap)
{
	size_t		r_c;
	int			cnt;
	int			idx;
	int			*idx_pt;

	r_c = 0;
	cnt = 0;
	idx = 0;
	idx_pt = &idx;
	while (form[idx])
	{
		if (form[idx] == '%')
		{
			cnt = is_printf_flag(form, idx_pt, ap);
			if (cnt == -1)
				return (-1);
			r_c += cnt;
		}
		else
			r_c += write(1, &form[idx], 1);
		idx++;
	}
	return (r_c);
}

int	ft_printf(const char *form, ...)
{
	va_list	ap;
	int		r_c;

	va_start(ap, form);
	r_c = count_printf((char *)form, ap);
	va_end(ap);
	return (r_c);
}

int	main(void)
{
	int i;
	int j;
	// ft_printf("%% ft_printf_test (clear)");
	// ft_printf("f %%%%, [%%]\n");
	// ft_printf("f %%5%%, [%5%]\n");
	// ft_printf("f %%-5%%, [%-5%]\n");
	// ft_printf("f %%05%%, [%05%]\n");
	// ft_printf("f %%-05%%, [%-05%]\n\n");
	// printf("%% printf_test");
	// printf("f %%%%, [%%]\n");
	// printf("f %%5%%, [%5%]\n");
	// printf("f %%-5%%, [%-5%]\n");
	// printf("f %%05%%, [%05%]\n");
	// printf("f %%-05%%, [%-05%]\n\n");

	// ft_printf("id basic test n width test (clear) \n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%i = 2147483647, [%i]\n", 2147483647);
	// ft_printf("f %%d = -2147483648, [%d]\n", (int)(-2147483648));
	// ft_printf("f %%d = 0, [%d]\n", 0);
	// ft_printf("f %%7i = 33,  [%7i]\n", 33);
	// ft_printf("f %%7d = -14, [%7d]\n", -14);
	// ft_printf("f %%3i = 0, [%3i]\n", 0);
	// ft_printf("f %%5d = 52625, [%5d]\n", 52625);
	// ft_printf("f %%5i = -2562, [%5i]\n", -2562);
	// ft_printf("f %%4d = 94827, [%4d]\n", 94827);
	// ft_printf("f %%4i = -2464, [%4i]\n", -2464);
	// ft_printf("f %%-7d = 33,  [%-7d]\n", 33);
	// ft_printf("f %%-7i = -14, [%-7i]\n", -14);
	// ft_printf("f %%-5i = 52625, [%-5i]\n", 52625);
	// ft_printf("f %%-5d = -2562, [%-5d]\n", -2562);
	// ft_printf("f %%-4d = 94827, [%-4d]\n", 94827);
	// ft_printf("f %%-4i = -2464, [%-4i]\n\n", -2464);
	// printf("printf test\n");
	// printf("f %%i = 2147483647, [%i]\n", 2147483647);
	// printf("f %%d = -2147483648, [%d]\n", (int)(-2147483648));
	// printf("f %%d = 0, [%d]\n", 0);
	// printf("f %%7i = 33,  [%7i]\n", 33);
	// printf("f %%7d = -14, [%7d]\n", -14);
	// printf("f %%3i = 0, [%3i]\n", 0);
	// printf("f %%5d = 52625, [%5d]\n", 52625);
	// printf("f %%5i = -2562, [%5i]\n", -2562);
	// printf("f %%4d = 94827, [%4d]\n", 94827);
	// printf("f %%4i = -2464, [%4i]\n", -2464);
	// printf("f %%-7d = 33,  [%-7d]\n", 33);
	// printf("f %%-7i = -14, [%-7i]\n", -14);
	// printf("f %%-5i = 52625, [%-5i]\n", 52625);
	// printf("f %%-5d = -2562, [%-5d]\n", -2562);
	// printf("f %%-4d = 94827, [%-4d]\n", 94827);
	// printf("f %%-4i = -2464, [%-4i]\n\n", -2464);


	// ft_printf("id precision test (clear)\n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%.i = 2, [%.i]\n", 2);
	// ft_printf("f %%.d = -3, [%.d]\n", -3);
	// ft_printf("f %%.5i = 2, [%.5i]\n", 2);
	// ft_printf("f %%.6d = -3, [%.6d]\n", -3);
	// ft_printf("f %%.3i = 0, [%.3i]\n", 0);
	// ft_printf("f %%.5d = 5263,  [%.5d]\n", 5263);
	// ft_printf("f %%.5d = -2372, [%.5d]\n", -2372);
	// ft_printf("f %%.7i = 13862,  [%.7i]\n", 13862);
	// ft_printf("f %%.7i = -23646, [%.7i]\n\n",-23646);
	// ft_printf("printf test\n");
	// printf("f %%.i = 2, [%.i]\n", 2);
	// printf("f %%.d = -3, [%.d]\n", -3);
	// printf("f %%.5i = 2, [%.5i]\n", 2);
	// printf("f %%.6d = -3, [%.6d]\n", -3);
	// printf("f %%.3i = 0, [%.3i]\n", 0);
	// printf("f %%.5d = 5263,  [%.5d]\n", 5263);
	// printf("f %%.5d = -2372, [%.5d]\n", -2372);
	// printf("f %%.7i = 13862,  [%.7i]\n", 13862);
	// printf("f %%.7i = -23646, [%.7i]\n\n",-23646);

	// ft_printf("id zero field width padding test (clear) \n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%05i = 43, [%05i]\n", 43);
	// ft_printf("f %%07d = -54, [%07d]\n", -54);
	// ft_printf("f %%03i = 0, [%03i]\n", 0);
	// ft_printf("f %%04d = 634, [%04d]\n", 634);
	// ft_printf("f %%04i = -532, [%04i]\n", -532);
	// ft_printf("f %%04d = -4825, [%04d]\n\n", -4825);
	// ft_printf("printf test\n");
	// printf("f %%05i = 43, [%05i]\n", 43);
	// printf("f %%07d = -54, [%07d]\n", -54);
	// printf("f %%03i = 0, [%03i]\n", 0);
	// printf("f %%04d = 634, [%04d]\n", 634);
	// printf("f %%04i = -532, [%04i]\n", -532);
	// printf("f %%04d = -4825, [%04d]\n\n", -4825);

	// ft_printf("id width and precision test (clear)\n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%8.5i = 34, [%8.5i]\n", 34);
	// ft_printf("f %%8.5i = 0, [%8.5i]\n", 0);
	// ft_printf("f %%8.3d = 8375,  [%8.3d]\n", 8375);
	// ft_printf("f %%8.3i = -8473, [%8.3i]\n", -8473);
	// ft_printf("f %%3.7d = 3267,  [%3.7d]\n", 3267);
	// ft_printf("f %%3.7i = -2375, [%3.7i]\n", -2375);
	// ft_printf("f %%3.3d = 6983,  [%3.3d]\n", 6983);
	// ft_printf("f %%3.3i = -8462, [%3.3i]\n", -8462);
	// ft_printf("f %%-8.5i = 34, [%-8.5i]\n", 34);
	// ft_printf("f %%-8.5i = 0, [%-8.5i]\n", 0);
	// ft_printf("f %%-3.8d = 8375,  [%-3.8d]\n", 8375);
	// ft_printf("f %%-3.8i = -8473, [%-3.8i]\n", -8473);
	// ft_printf("f %%-3.7d = 3267,  [%-3.7d]\n", 3267);
	// ft_printf("f %%-3.7i = -2375, [%-3.7i]\n", -2375);
	// ft_printf("f %%-3.3d = 6983,  [%-3.3d]\n", 6983);
	// ft_printf("f %%-3.3i = -8462, [%-3.3i]\n\n", -8462);
	// ft_printf("printf test\n");
	// printf("f %%8.5i = 34, [%8.5i]\n", 34);
	// printf("f %%8.5i = 0, [%8.5i]\n", 0);
	// printf("f %%8.3d = 8375,  [%8.3d]\n", 8375);
	// printf("f %%8.3i = -8473, [%8.3i]\n", -8473);
	// printf("f %%3.7d = 3267,  [%3.7d]\n", 3267);
	// printf("f %%3.7i = -2375, [%3.7i]\n", -2375);
	// printf("f %%3.3d = 6983,  [%3.3d]\n", 6983);
	// printf("f %%3.3i = -8462, [%3.3i]\n", -8462);
	// printf("f %%-8.5i = 34, [%-8.5i]\n", 34);
	// printf("f %%-8.5i = 0, [%-8.5i]\n", 0);
	// printf("f %%-3.8d = 8375,  [%-3.8d]\n", 8375);
	// printf("f %%-3.8i = -8473, [%-3.8i]\n", -8473);
	// printf("f %%-3.7d = 3267,  [%-3.7d]\n", 3267);
	// printf("f %%-3.7i = -2375, [%-3.7i]\n", -2375);
	// printf("f %%-3.3d = 6983,  [%-3.3d]\n", 6983);
	// printf("f %%-3.3i = -8462, [%-3.3i]\n\n", -8462);

	// ft_printf("id width and precision with zeropadding test (clear)\n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%08.5i = 34, [%08.5i]\n", 34);
	// ft_printf("f %%010.5d = -216, [%010.5d]\n", -216);
	// ft_printf("f %%08.5i = 0, [%08.5i]\n", 0);
	// ft_printf("f %%08.3d = 8375,  [%08.3d]\n", 8375);
	// ft_printf("f %%08.3i = -8473, [%08.3i]\n", -8473);
	// ft_printf("f %%03.7d = 3267,  [%03.7d]\n", 3267);
	// ft_printf("f %%03.7i = -2375, [%03.7i]\n", -2375);
	// ft_printf("f %%03.3d = 6983,  [%03.3d]\n", 6983);
	// ft_printf("f %%03.3i = -8462, [%03.3i]\n\n", -8462);
	// ft_printf("printf test\n");
	// printf("f %%08.5i = 34, [%08.5i]\n", 34);
	// printf("f %%010.5d = -216, [%010.5d]\n", -216);
	// printf("f %%08.5i = 0, [%08.5i]\n", 0);
	// printf("f %%08.3d = 8375,  [%08.3d]\n", 8375);
	// printf("f %%08.3i = -8473, [%08.3i]\n", -8473);
	// printf("f %%03.7d = 3267,  [%03.7d]\n", 3267);
	// printf("f %%03.7i = -2375, [%03.7i]\n", -2375);
	// printf("f %%03.3d = 6983,  [%03.3d]\n", 6983);
	// printf("f %%03.3i = -8462, [%03.3i]\n\n", -8462);

	// ft_printf("id width and precision, left-justified with zeropadding test (clear)\n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%0-8.5i = 34, [%0-8.5i]\n", 34);
	// ft_printf("f %%0-10.5d = -216, [%0-10.5d]\n", -216);
	// ft_printf("f %%0-8.5i = 0, [%0-8.5i]\n", 0);
	// ft_printf("f %%0-8.3d = 8375,  [%0-8.3d]\n", 8375);
	// ft_printf("f %%0-8.3i = -8473, [%0-8.3i]\n", -8473);
	// ft_printf("f %%0-3.7d = 3267,  [%0-3.7d]\n", 3267);
	// ft_printf("f %%0-3.7i = -2375, [%0-3.7i]\n", -2375);
	// ft_printf("f %%0-3.3d = 6983,  [%0-3.3d]\n", 6983);
	// ft_printf("f %%0-3.3i = -8462, [%0-3.3i]\n\n", -8462);
	// ft_printf("printf test\n");
	// printf("f %%0-8.5i = 34, [%0-8.5i]\n", 34);
	// printf("f %%0-10.5d = -216, [%0-10.5d]\n", -216);
	// printf("f %%0-8.5i = 0, [%0-8.5i]\n", 0);
	// printf("f %%0-8.3d = 8375,  [%0-8.3d]\n", 8375);
	// printf("f %%0-8.3i = -8473, [%0-8.3i]\n", -8473);
	// printf("f %%0-3.7d = 3267,  [%0-3.7d]\n", 3267);
	// printf("f %%0-3.7i = -2375, [%0-3.7i]\n", -2375);
	// printf("f %%0-3.3d = 6983,  [%0-3.3d]\n", 6983);
	// printf("f %%0-3.3i = -8462, [%0-3.3i]\n\n", -8462);

	// ft_printf("id zero test (clear) \n");
	// ft_printf("ft_printf\n");
	// ft_printf("f %%i = 0,   [%i]\n", 0);
	// ft_printf("f %%5i = 0,   [%5i]\n", 0);
	// ft_printf("f %%.0i = 0,   [%.0i]\n", 0);
	// ft_printf("f %%.i = 0,    [%.i]\n", 0);
	// ft_printf("f %%5.0i = 0,  [%5.0i]\n", 0);
	// ft_printf("f %%5.i = 0,   [%5.i]\n", 0);
	// ft_printf("f %%-5.0i = 0, [%-5.0i]\n", 0);
	// ft_printf("f %%-5.i = 0,  [%-5.i]\n\n", 0);
	// printf("printf\n");
	// printf("f %%i = 0,   [%i]\n", 0);
	// printf("f %%5i = 0,   [%5i]\n", 0);
	// printf("f %%.0i = 0,   [%.0i]\n", 0);
	// printf("f %%.i = 0,    [%.i]\n", 0);
	// printf("f %%5.0i = 0,  [%5.0i]\n", 0);
	// printf("f %%5.i = 0,   [%5.i]\n", 0);
	// printf("f %%-5.0i = 0, [%-5.0i]\n", 0);
	// printf("f %%-5.i = 0,  [%-5.i]\n\n", 0);

	// ft_printf("id space test (clear)\n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %% i = 34, [% i]\n", 34);
	// ft_printf("f %% d = -216, [% d]\n", -216);
	// ft_printf("f %% 3.3d = 8375,  [% 3.3d]\n", 8375);
	// ft_printf("f %% 3.3i = -8473, [% 3.3i]\n", -8473);
	// ft_printf("f %% 8.3d = 8375,  [% 8.3d]\n", 8375);
	// ft_printf("f %% 8.3i = -8473, [% 8.3i]\n", -8473);
	// ft_printf("f %% 3.7d = 3267,  [% 3.7d]\n", 3267);
	// ft_printf("f %% 3.7i = -2375, [% 3.7i]\n\n", -2375);
	// ft_printf("printf test\n");
	// printf("f %% i = 34, [% i]\n", 34);
	// printf("f %% d = -216, [% d]\n", -216);
	// printf("f %% 3.3d = 8375,  [% 3.3d]\n", 8375);
	// printf("f %% 3.3i = -8473, [% 3.3i]\n", -8473);
	// printf("f %% 8.3d = 8375,  [% 8.3d]\n", 8375);
	// printf("f %% 8.3i = -8473, [% 8.3i]\n", -8473);
	// printf("f %% 3.7d = 3267,  [% 3.7d]\n", 3267);
	// printf("f %% 3.7i = -2375, [% 3.7i]\n\n", -2375);

	// ft_printf("id plus sign test (clear) \n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%+i = 34, [%+i]\n", 34);
	// ft_printf("f %%+d = -216, [%+d]\n", -216);
	// ft_printf("f %%+3.3d = 8375,  [%+3.3d]\n", 8375);
	// ft_printf("f %%+3.3i = -8473, [%+3.3i]\n", -8473);
	// ft_printf("f %%+8.3d = 8375,  [%+8.3d]\n", 8375);
	// ft_printf("f %%+8.3i = -8473, [%+8.3i]\n", -8473);
	// ft_printf("f %%+3.7d = 3267,  [%+3.7d]\n", 3267);
	// ft_printf("f %%+3.7i = -2375, [%+3.7i]\n\n", -2375);
	// ft_printf("printf test\n");
	// printf("f %%+i = 34, [%+i]\n", 34);
	// printf("f %%+d = -216, [%+d]\n", -216);
	// printf("f %%+3.3d = 8375,  [%+3.3d]\n", 8375);
	// printf("f %%+3.3i = -8473, [%+3.3i]\n", -8473);
	// printf("f %%+8.3d = 8375,  [%+8.3d]\n", 8375);
	// printf("f %%+8.3i = -8473, [%+8.3i]\n", -8473);
	// printf("f %%+3.7d = 3267,  [%+3.7d]\n", 3267);
	// printf("f %%+3.7i = -2375, [%+3.7i]\n\n", -2375);

	// ft_printf("id space with plus sign test (clear)\n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%+ i = 34, [%+ i]\n", 34);
	// ft_printf("f %%+ d = -216, [%+ d]\n", -216);
	// ft_printf("f %%+ 3.3d = 8375,  [%+ 3.3d]\n", 8375);
	// ft_printf("f %%+ 3.3i = -8473, [%+ 3.3i]\n", -8473);
	// ft_printf("f %%+ 8.3d = 8375,  [%+ 8.3d]\n", 8375);
	// ft_printf("f %%+ 8.3i = -8473, [%+ 8.3i]\n", -8473);
	// ft_printf("f %%+ 3.7d = 3267,  [%+ 3.7d]\n", 3267);
	// ft_printf("f %%+ 3.7i = -2375, [%+ 3.7i]\n\n", -2375);
	// ft_printf("printf test\n");
	// printf("f %%+ i = 34, [%+ i]\n", 34);
	// printf("f %%+ d = -216, [%+ d]\n", -216);
	// printf("f %%+ 3.3d = 8375,  [%+ 3.3d]\n", 8375);
	// printf("f %%+ 3.3i = -8473, [%+ 3.3i]\n", -8473);
	// printf("f %%+ 8.3d = 8375,  [%+ 8.3d]\n", 8375);
	// printf("f %%+ 8.3i = -8473, [%+ 8.3i]\n", -8473);
	// printf("f %%+ 3.7d = 3267,  [%+ 3.7d]\n", 3267);
	// printf("f %%+ 3.7i = -2375, [%+ 3.7i]\n\n", -2375);

	// ft_printf("u - unsigned int test (clear) \n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %u\n", 4294967295u);
	// ft_printf("%u\n", 42);
	// ft_printf("Kashim a %u histoires à raconter\n", 1001);
	// ft_printf("Il fait au moins %u\n", -8000);
	// ft_printf("%u\n", -0);
	// ft_printf("%u\n", 0);
	// ft_printf("%u\n", INT_MAX);
	// ft_printf("%u\n", INT_MIN);
	// ft_printf("%u\n", INT_MIN - 1);
	// ft_printf("%u\n", INT_MAX + 1);
	// ft_printf("f %%-10u = 52625, [%-10u]\n", 52625);
	// ft_printf("f %%-15u = -2562, [%-15u]\n", -2562);
	// ft_printf("f %%-10.7u = 52625, [%-10u]\n", 52625);
	// ft_printf("f %%15.12u = 2562, [%15.12u]\n", 2562);
	// ft_printf("f %%10.7u = 94827, [%10.7u]\n", 94827);
	// ft_printf("f %%15.5u = -2464, [%15.5u]\n", -2464);
	// ft_printf("%%u 0000042 == |%u|\n", 0000042);
	// ft_printf("%%u \t == |%u|\n", '\t');
	// ft_printf("%%u Lydie == |%u|\n\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("printf_test\n");
	// printf("f %u\n", 4294967295u);
	// printf("%u\n", 42);
	// printf("Kashim a %u histoires à raconter\n", 1001);
	// printf("Il fait au moins %u\n", -8000);
	// printf("%u\n", -0);
	// printf("%u\n", 0);
	// printf("%u\n", INT_MAX);
	// printf("%u\n", INT_MIN);
	// printf("%u\n", INT_MIN - 1);
	// printf("%u\n", INT_MAX + 1);
	// printf("f %%-10u = 52625, [%-10u]\n", 52625);
	// printf("f %%-15u = -2562, [%-15u]\n", -2562);
	// printf("f %%-10.7u = 52625, [%-10u]\n", 52625);
	// printf("f %%15.12u = 2562, [%15.12u]\n", 2562);
	// printf("f %%10.7u = 94827, [%10.7u]\n", 94827);
	// printf("f %%15.5u = -2464, [%15.5u]\n", -2464);
	// printf("%u\n", INT_MIN - 1);
	// printf("%u\n", INT_MAX + 1);
	// printf("%%u 0000042 == |%u|\n", 0000042);
	// printf("%%u \t == |%u|\n", '\t');
	// printf("%%u Lydie == |%u|\n\n", 'L'+'y'+'d'+'i'+'e');

	// ft_printf("X - unsigned hexadecimal test (clear) \n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%X 4294967295u = [%X]\n", 4294967295u);
	// ft_printf("f %%-X 42 = [%-X]\n", 42);
	// ft_printf("f Kashim a [%X] histoires à raconter\n", 1001);
	// ft_printf("f Il fait au moins [%X]\n", -8000);
	// ft_printf("f %%08X -0 = [%08X]\n", -0);
	// ft_printf("f %%.8X 0 = [%.8X]\n", 0);
	// ft_printf("f %%#X INT_MAX = [%#X]\n", INT_MAX);
	// ft_printf("f %%8.0X INT_MAX = [%8.0X]\n", INT_MIN);
	// ft_printf("f %%0.8X INT_MAX - 1= [%0.8X]\n", INT_MIN - 1);
	// ft_printf("f %%8X INT_MAX + 1= [%8X]\n", INT_MAX + 1);
	// ft_printf("f %%8X 0000042 == |%8X|\n", 0000042);
	// ft_printf("f %%#8X 0000042 == |%#8X|\n", 0000042);
	// ft_printf("f %%-8X (tab) \t == |%-8X]\n", '\t');
	// ft_printf("f %%-8.0X Lydie == |%-8.0X|\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("f %%#-8.0X Lydie == |%#-8.0X|\n\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("printf test\n");
	// printf("f %%X 4294967295u = [%X]\n", 4294967295u);
	// printf("f %%-X 42 = [%-X]\n", 42);
	// printf("f Kashim a [%X] histoires à raconter\n", 1001);
	// printf("f Il fait au moins [%X]\n", -8000);
	// printf("f %%08X -0 = [%08X]\n", -0);
	// printf("f %%.8X 0 = [%.8X]\n", 0);
	// printf("f %%#X INT_MAX = [%#X]\n", INT_MAX);
	// printf("f %%8.0X INT_MAX = [%8.0X]\n", INT_MIN);
	// printf("f %%0.8X INT_MAX - 1= [%0.8X]\n", INT_MIN - 1);
	// printf("f %%8X INT_MAX + 1= [%8X]\n", INT_MAX + 1);
	// printf("f %%8X 0000042 == |%8X|\n", 0000042);
	// printf("f %%#8X 0000042 == |%#8X|\n", 0000042);
	// printf("f %%-8X (tab) \t == |%-8X]\n", '\t');
	// printf("f %%-8.0X Lydie == |%-8.0X|\n", 'L'+'y'+'d'+'i'+'e');
	// printf("f %%#-8.0X Lydie == |%#-8.0X|\n\n", 'L'+'y'+'d'+'i'+'e');

	// ft_printf("x - unsigned hexadecimal test (clear) \n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%x 4294967295u = [%x]\n", 4294967295u);
	// ft_printf("f %%-x 42 = [%-x]\n", 42);
	// ft_printf("f %%-x -42 = [%-x]\n", -42);
	// ft_printf("f Kashim a [%x] histoires à raconter\n", 1001);
	// ft_printf("f Il fait au moins [%x]\n", -8000);
	// ft_printf("f %%08x -0 = [%08x]\n", -0);
	// ft_printf("f %%.8x 0 = [%.8x]\n", 0);
	// ft_printf("f %%#x INT_MAX = [%#x]\n", INT_MAX);
	// ft_printf("f %%8.0x INT_MAX = [%8.0x]\n", INT_MIN);
	// ft_printf("f %%0.8x INT_MAX - 1= [%0.8x]\n", INT_MIN - 1);
	// ft_printf("f %%8x INT_MAX + 1= [%8x]\n", INT_MAX + 1);
	// ft_printf("f %%8x 0000042 == |%8x|\n", 0000042);
	// ft_printf("f %%#8x 0000042 == |%#8x|\n", 0000042);
	// ft_printf("f %%-8x (tab) \t == |%-8x|\n", '\t');
	// ft_printf("f %%-8.0x Lydie == |%-8.0x|\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("f %%#-8.0x Lydie == |%#-8.0x|\n\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("printf test \n");
	// printf("f %%x 4294967295u = [%x]\n", 4294967295u);
	// printf("f %%-x 42 = [%-x]\n", 42);
	// printf("f %%-x -42 = [%-x]\n", -42);
	// printf("f Kashim a [%x] histoires à raconter\n", 1001);
	// printf("f Il fait au moins [%x]\n", -8000);
	// printf("f %%08x -0 = [%08x]\n", -0);
	// printf("f %%.8x 0 = [%.8x]\n", 0);
	// printf("f %%#x INT_MAX = [%#x]\n", INT_MAX);
	// printf("f %%8.0x INT_MAX = [%8.0x]\n", INT_MIN);
	// printf("f %%0.8x INT_MAX - 1= [%0.8x]\n", INT_MIN - 1);
	// printf("f %%8x INT_MAX + 1= [%8x]\n", INT_MAX + 1);
	// printf("f %%8x 0000042 == |%8x|\n", 0000042);
	// printf("f %%#8x 0000042 == |%#8x|\n", 0000042);
	// printf("f %%-8x (tab) \t == |%-8x|\n", '\t');
	// printf("f %%-8.0x Lydie == |%-8.0x|\n", 'L'+'y'+'d'+'i'+'e');
	// printf("f %%#-8.0x Lydie == |%#-8.0x|\n\n", 'L'+'y'+'d'+'i'+'e');

	// ft_printf("p - pointer test (clear) \n");
	// ft_printf("ft_printf test\n");
	// ft_printf("f %%p NULL == [%p]\n", NULL);
	// ft_printf("f %%5p NULL == [%5p]\n", NULL);
	// ft_printf("f %%2p 1234 == [%2p]\n", 1234);
	// ft_printf("f %%5p 0 == [%5p]\n\n", 0);
	// ft_printf("printf test\n");
	// printf("f %%p NULL == [%p]\n", NULL);
	// printf("f %%5p NULL == [%5p]\n", NULL);
	// printf("f %%2p 1234 == [%2p]\n", 1234);
	// printf("f %%5p 0 == [%5p]\n\n", 0);

	ft_printf("c - char test \n");
	ft_printf("ft_printf test\n");
	ft_printf("%%c 42 == [%c]\n", 42);
	ft_printf("[Kashim a [%c] histoires à raconter]\n", 1001);
	ft_printf("[Il fait au moins [%c]]\n", -8000);
	ft_printf("%%c -0 == [%c]\n", -0);
	ft_printf("%%c 0 == [%c]\n", 0);
	ft_printf("%%c INT_MAX == [%c]\n", INT_MAX);
	ft_printf("%%4c 'c' == [%4c]\n", 'c');
	ft_printf("%%-2c '\\n' == [%-2c]\n", '\n');
	ft_printf("%%04c 'l' == [%04c]\n", 'l');
	ft_printf("%% c 'y' == [% c]\n", 'y');
	ft_printf("%%c ' ' == [%c]\n", ' ');
	ft_printf("%%#c 'e' == [%#c]\n", 'e');
	ft_printf("%%+c 's' == [%+c]\n", 's');
	ft_printf("%%.2c 't' == [%.2c]\n", 't');
	ft_printf("%%c 'f' == [%c]\n", 'f');
	ft_printf("%%c '\\r' == [%c]\n", '\r');
	ft_printf("%%c '\\t' == [%c]\n\n", '\t');
	ft_printf("printf test\n");
	printf("%%c 42 == [%c]\n", 42);
	printf("[Kashim a [%c] histoires à raconter]\n", 1001);
	printf("[Il fait au moins [%c]]\n", -8000);
	printf("%%c -0 == [%c]\n", -0);
	printf("%%c 0 == [%c]\n", 0);
	printf("%%c INT_MAX == [%c]\n", INT_MAX);
	printf("%%4c 'c' == [%4c]\n", 'c');
	printf("%%-2c '\\n' == [%-2c]\n", '\n');
	printf("%%04c 'l' == [%04c]\n", 'l');
	printf("%% c 'y' == [% c]\n", 'y');
	printf("%%c ' ' == [%c]\n", ' ');
	printf("%%#c 'e' == [%#c]\n", 'e');
	printf("%%+c 's' == [%+c]\n", 's');
	printf("%%.2c 't' == [%.2c]\n", 't');
	printf("%%c 'f' == [%c]\n", 'f');
	printf("%%c '\\r' == [%c]\n", '\r');
	printf("%%c '\\t' == [%c]\n\n", '\t');

	return (0);
}
