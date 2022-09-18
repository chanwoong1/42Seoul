/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:44:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/17 16:39:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
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
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (sign * ret);
}

void	valid_arg(t_ph *ph, char *av, int i)
{
	int	idx;

	idx = 0;
	while (av[idx])
	{
		if (!(av[idx] >= '0' && av[idx] <= '9'))
		{
			ph->args[i] = -1;
			return ;
		}
		idx++;
	}
	ph->args[i] = ft_atoi(av);
}

int valid_args(t_ph *ph, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < 5 + ac)
	{
		valid_arg(ph, av[i], i);
		if (ph->args[i] < 0)
			return (FAIL);
		i++;
	}
	if (i == 4)
		ph->args[i] = 0;
	return (SUCCESS);
}

void	create_philo(t_ph *ph)
{
	int i;

	i = 0;
	ph->philo = 

}

int	main(int ac, char **av)
{
	t_ph	ph;

	if (!(ac >= 5 && ac <= 6))
		return (FAIL);
	memset(&ph, 0, sizeof(t_ph));
	if (valid_args(&ph, ac - 6, av + 1) == FAIL)
		return (FAIL);
	create_philo(&ph);
	system("leaks philosophers");
	return (0);
}
