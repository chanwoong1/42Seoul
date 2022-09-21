/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:44:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/21 20:18:31 by chanwjeo         ###   ########.fr       */
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

void	valid_arg(t_arg *args, char *av, int i)
{
	int	idx;

	idx = 0;
	while (av[idx])
	{
		if (!(av[idx] >= '0' && av[idx] <= '9'))
		{
			args->args[i] = -1;
			return ;
		}
		idx++;
	}
	args->args[i] = ft_atoi(av);
}

int valid_args(t_arg *arg, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < 5 + ac)
	{
		valid_arg(arg, av[i], i);
		if (arg->args[i] < 0)
			return (FAIL);
		i++;
	}
	if (i == 4)
		arg->args[i] = 0;
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo;
	int		errno;

	if (argc != 5 && argc != 6)
		return (FAIL);
	memset(&arg, 0, sizeof(t_arg));
	if (valid_args(&args, ac - 6, av + 1) == FAIL)
		return (FAIL);

// argv를 구조체에 저장하고 필요한 변수들을 할당하고 초기화해준다
	
	errno = ft_philo_init(&philo, &arg);
	if (errno)
		return (print_error("error philo init", errno));
// 철학자별로 들어갈 변수들을 초기화한다.

	errno = ft_philo_start(&arg, philo);
	if (errno)
		return (print_error("error philo start", errno));
// 철학자를 시작하고 종료될때까지 동작한다
	return (0);
}
