/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:52:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/14 16:01:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ps_atoi(const char *str)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		ps_error();
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if (ret * sign > 2147483647 || ret * sign < -2147483648)
		ps_error();
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

static void	overlap_checker(t_var *stacks, int check)
{
	int		*new_tmp;
	int		idx;

	idx = 0;
	while (idx < stacks->list_size)
	{
		if (stacks->list[idx] - check == 0)
			ps_error();
		idx++;
	}
	stacks->list_size++;
	new_tmp = (int *)malloc(sizeof(int) * stacks->list_size);
	if (stacks->list_size == 1)
		new_tmp[0] = check;
	else
	{
		idx = -1;
		while (++idx < stacks->list_size - 1)
			new_tmp[idx] = stacks->list[idx];
		new_tmp[idx] = check;
	}
	free(stacks->list);
	stacks->list = new_tmp;
}

void	validate_args(int ac, char **av, t_var *stacks)
{
	int		tmp_idx;
	int		tmp_size;
	char	*args;
	char	**tmp;
	t_node	*new_node;

	args = ps_all_join(ac, av);
	tmp_size = ps_size_check(args, ' ');
	tmp = ft_split(args, ' ');
	free(args);
	tmp_idx = 0;
	while (tmp_idx < tmp_size)
	{
		if (!ps_valid_atoi(tmp[tmp_idx]))
			ps_error();
		new_node = get_new_node(ps_atoi(tmp[tmp_idx]));
		free(tmp[tmp_idx]);
		overlap_checker(stacks, new_node->val);
		tmp_idx++;
		free(new_node);
	}
	free(tmp);
}
