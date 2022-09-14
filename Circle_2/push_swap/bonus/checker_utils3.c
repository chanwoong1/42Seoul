/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:47:50 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/27 12:50:47 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ps_all_join(int ac, char **av)
{
	long long	i;
	long long	len;
	char		*str;
	long long	idx;
	long long	j;

	i = 0;
	idx = 0;
	len = 0;
	while (++i < ac)
		len += ft_strlen(av[i]);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + ac));
	if (!str)
		return (NULL);
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
			str[idx++] = av[i][j++];
		if (i != ac - 1)
			str[idx++] = ' ';
	}
	str[idx] = '\0';
	return (str);
}
