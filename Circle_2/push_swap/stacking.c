/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:52:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/18 20:10:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	ps_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
	{
		ps_error();
		return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (sign * ret);
}

static int	ps_size_check(char const *str, char c)
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

static int	ps_valid_atoi(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_strchr("+-0123456789", str[idx]))
			return (0);
		idx++;
	}
	return (1);
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

void	overlap_checker(t_var *stacks, char *check)
{
	char	**overlap_list;
	char	**tmp_list;
	char	**new_tmp;
	int		list_size;
	int		idx;

	overlap_list = stacks->list;
	list_size = stacks->list_size;
	idx = 0;
	while (idx < list_size)
	{
		if (ft_strncmp(overlap_list[idx], check, ft_strlen(check)))
			ps_error();
		idx++;
	}
	list_size++;
	new_tmp = (char **)malloc(sizeof(char));
	new_tmp[0] = 0;
	idx = 0;
	while (overlap_list[idx])
	{
		tmp_list = ft_strjoin(new_tmp, overlap_list[idx]);
		free_arr(new_tmp, idx);
		new_tmp = tmp_list;
		idx++;
	}
	tmp_list = ft_strjoin(new_tmp, check);
	free_arr(new_tmp, idx);
	free_arr(stacks->list);
	stacks->list = tmp_list;
}

void	valid_stacking_args(int ac, char **av, t_var *stacks)
{
	int		idx;
	int		tmp_idx;
	int		tmp_size;
	char	**tmp;
	t_node	*new_node;

	idx = 1;
	while (idx < ac)
	{
		if ((tmp_size = ps_size_check(av[idx], ' ')) == 0)
			ps_error();
		tmp = ft_split(av[idx], ' ');
		tmp_idx = 0;
		while (tmp_idx < tmp_size)
		{
			if (!ps_valid_atoi(tmp[tmp_idx]))
				ps_error();
			new_node = get_new_node(ps_atoi(tmp[tmp_idx]));
			overlab_checker(stacks, tmp[tmp_idx]);
			push_top(stacks->stack_a, new_node);
			tmp_idx++;
		}
		idx++;
	}
}
