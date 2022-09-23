/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:44:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/22 12:52:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_error(char *msg, int err)
{
	printf("%s : %d\n", msg, err);
	return (err);
}

int	ft_atoi(const char *str)
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
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if (ret > 9223372036854775807 && sign == -1)
		return (-1);
	else if (ret > 9223372036854775807)
		return (-1);
	return (sign * ret);
}

long long	ft_get_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (-1);
	return ((mytime.tv_sec * 1000) + (mytime.tv_usec / 1000));
}

void	ft_pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (!(arg->finish))
	{
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}

void	*ft_thread(void *argv)
{
	t_arg		*arg;
	t_philo		*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2)
		usleep(1000);
	while (!arg->finish)
	{
		ft_philo_action(arg, philo);
		if (arg->eat_times == philo->eat_count)
		{
			arg->finished_eat++;
			break ;
		}
		ft_philo_printf(arg, philo->id, "is sleeping");
		ft_pass_time((long long)arg->time_to_sleep, arg);
		ft_philo_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_philo	*philo;
	int		err;

	if (argc != 5 && argc != 6)
		return (FAIL);
	memset(&arg, 0, sizeof(t_arg));
	err = ft_arg_init(&arg, argc, argv);
	if (err)
		return (print_error("error arg init", err));
	err = ft_philo_init(&philo, &arg);
	if (err)
		return (print_error("error philo init", err));
	err = ft_philo_start(&arg, philo);
	if (err)
		return (print_error("error philo start", err));
	system("leaks philo");
	return (0);
}
