/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:25:00 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/07/11 15:35:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_size_check(char const *str, char *charset)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
			size++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (size);
}

int	ft_str_check(char const *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

char	**ft_too_many_lines(char **arr, char const *str, char *charset, int i)
{
	int	len;
	int	j;

	len = ft_str_check(str, charset);
	arr[i] = (char *)malloc(sizeof(char) * (len + 1));
	j = 0;
	while (j < len)
	{
		arr[i][j] = str[j];
		j++;
	}
	arr[i][j] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char *c)
{
	char	**split;
	int		size;
	int		i;

	i = 0;
	size = ft_size_check(s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
		{
			split = ft_too_many_lines(split, s, c, i);
			i++;
		}
		while (*s && !is_sep(*s, c))
			s++;
	}
	split[i] = 0;
	return (split);
}

/*
#include <stdio.h>
int main(void)
{
	char *s = "He@@llo, Wor!!ld! 12!@#$34#689*879&8a^scnkp#oqnk@al!wiihuv";
	char *c = " !@#$^&()*";
	char **result;

	printf("\n--------------------\n");
	printf("%s%s\n", "s : ", s);
	printf("%s%s\n", "c : ", c);
	result = ft_split(s, c);
	int i = 0;
	int j = 0;
	while (result[i])
		i++;
	printf("%s%d\n", "str's size : ", i);
	printf("%s\n", "split");
	while (j < i)
	{
		printf("%s%s%s ", "[", result[j], "]");
		j++;
	}
	return 0;
}
*/