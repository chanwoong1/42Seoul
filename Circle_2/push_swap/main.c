/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:15:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/11 12:16:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

// int	ft_atoi(const char *str)
// {
// 	int	ret;
// 	int	sign;

// 	ret = 0;
// 	sign = 1;
// 	while (*str == ' ' || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '-')
// 		sign = -1;
// 	if (*str == '+' || *str == '-')
// 		str++;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		ret = ret * 10 + (*str - '0');
// 		str++;
// 	}
// 	return (sign * ret);
// }

size_t	ps_2d_len(char **arr)
{
	size_t	size;

	size = 0;
	while (arr[size] != (void *)0)
		size++;
	return (size);
}

void	free_arr(char **arr)
{
	size_t	size;

	size = ps_2d_len(arr);
	while (size > 0)
	{
		free(arr[size - 1]);
		size--;
	}
	free(arr);
}

static void	ps_arrcat(char **dest, char **src)
{
	size_t	idx;
	size_t	s_idx;
	size_t	ss_idx;

	idx = 0;
	s_idx = 0;
	while (dest[idx] != (void *)0)
		idx++;
	while (src[s_idx] != (void *)0)
	{
		dest[idx] = (char *)malloc(sizeof(char) * (ft_strlen(src[s_idx]) + 1));
		ss_idx = 0;
		while (src[s_idx][ss_idx])
		{
			dest[idx][ss_idx] = src[s_idx][ss_idx];
			ss_idx++;
		}
		dest[idx][ss_idx] = '\0';
		idx++;
		s_idx++;
	}
	dest[idx] = (void *)0;
}

char	**ps_arrjoin(char **arr1, char **arr2)
{
	char	**copy;
	size_t	arr1_size;
	size_t	arr2_size;
	size_t	size;

	if (!arr1 || !arr2)
		return (0);
	arr1_size = ps_2d_len(arr1);
	arr2_size = ps_2d_len(arr2);
	size = arr1_size + arr2_size;
	copy = (char **)malloc(sizeof(char*) * (size + 1));
	if (!copy)
		return (0);
	copy[0] = (void *)0;
	ps_arrcat(copy, arr1);
	ps_arrcat(copy + arr1_size, arr2);
	free_arr(arr1);
	return (copy);
}

int	val_av(int ac, char **av, int **a)
{
	int	idx;
	int	str_idx;

	idx = 1;
	while (idx < ac)
	{
		str_idx = 0;
		while (av[idx][str_idx])
		{
			if (ft_strchr("-012345679", av[idx][str_idx]) == 0)
			{
				free(*a);
				return (FAIL);
			}
			str_idx++;
		}
		*a[idx - 1] = ft_atoi(av[idx]);
		idx++;
	}
	return (SUCCESS);
}

char	**av_checker(int ac, char **av)
{
	int		idx;
	size_t	jdx;
	char	**a;
	char	**tmp;
	char	**new_a;

	idx = 1;
	if (!(a = (char **)malloc(sizeof(char *))))
		return (NULL);
	a[0] = 0;
	while (idx < ac)
	{
		if (ft_strchr(av[idx], ' ') != 0)
		{
			if (!(tmp = ft_split(av[idx], ' ')))
			{
				free_arr(a);
				return (NULL);
			}
			new_a = ps_arrjoin(a, tmp);
			a = new_a;
			free_arr(tmp);
		}
		else
		{
			if (!(a[idx - 1] = (char *)malloc(sizeof(char) * ft_strlen(av[idx]) + 1)))
			{
				free_arr(a);
				return (NULL);
			}
			jdx = 0;
			while (jdx < ft_strlen(av[idx]))
			{
				a[idx - 1][jdx] = av[idx][jdx];
				jdx++;
			}
			a[idx - 1][jdx] = '\0';
		}
		idx++;
	}
	a[idx - 1] = 0;
	return (a);
}

int	main(int ac, char **av)
{
	int		*a;
	char	**tmp_a;

	if (ac <= 1)
		return (FAIL);
	if (!(tmp_a = av_checker(ac, av)))
		return (FAIL);
	int n = 0;
	ac = ps_2d_len(tmp_a) - 1;
	if (!(a = (int *)malloc(sizeof(int) * ac)))
		return (FAIL);
	free_arr(tmp_a);
	if (val_av(ac, tmp_a, &a) == FAIL)
		return (FAIL);
	printf("val_av clear\n");
	printf("a : ");
	n = 0;
	while (a[n] != '\0')
		printf("%d ", a[n]);
	return (SUCCESS);
}
