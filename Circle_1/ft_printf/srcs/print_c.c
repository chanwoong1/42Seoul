/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:55:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/01 16:33:55 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
	{
		write(fd, &s[0], 1);
		s++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, size_t n)
{
	int		idx;
	size_t		size_s1;
	size_t		size_s2;
	char	*join;
	size_t		limit;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (size_s1 + n) + 1);
	if (!join)
		return (NULL);
	idx = 0;
	while (*s1)
		join[idx++] = *s1++;
	limit = 0;
	while (*s2 && limit++ < n)
		join[idx++] = *s2++;
	join[idx] = '\0';
	return (join);
}

int	ft_print_c(char **print, va_list *ap)
{
	char	args;
	char	*tmp;
	size_t	print_size;

	print_size = ft_strlen(*print);
	args = va_arg(*ap, int);
	tmp = ft_strjoin(*print, &args, 1);
	if (!tmp)
		return (0);
	free(*print);
	*print = tmp;
	return (1);
}

int	ft_print_s(char **print, va_list *ap)
{
	char	*args;
	char	*tmp;
	size_t	print_size;

	print_size = ft_strlen(*print);
	args = va_arg(*ap, char *);
	tmp = ft_strjoin(*print, args, ft_strlen(args));
	if (!tmp)
		return (0);
	free(*print);
	*print = tmp;
	return (1);
}
