/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:25:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/11 09:44:20 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_check(char const *str, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

static int	ft_str_check(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	free_arr(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

char	**ft_too_many_lines(char **arr, char const *str, char c, int i)
{
	int	len;
	int	j;

	len = ft_str_check(str, c);
	arr[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr[i])
	{
		free_arr(arr, i);
		return (0);
	}
	j = 0;
	while (j < len)
	{
		arr[i][j] = str[j];
		j++;
	}
	arr[i][j] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;
	int		i;

	if (!s)
		return (0);
	i = 0;
	size = ft_size_check(s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split = ft_too_many_lines(split, s, c, i);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	split[i] = 0;
	return (split);
}
