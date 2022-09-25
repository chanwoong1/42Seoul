/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:19:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/25 21:04:05 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ph_stat_printf(t_arg *arg, int id, char *msg)
{
	long long	now;

	sem_wait(arg->print);
	now = get_time();
	if (now == -1)
		return (-1);
	// if (arg->finish)
	// 	exit(0);
	if (!(arg->finish))
		printf("%lld %d %s\n", now - arg->start_time, id + 1, msg);
	if (ft_strncmp(msg, "died", 4) == 0)
		return (0);
	sem_post(arg->print);
	return (0);
}

int	ph_start(t_arg *arg, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < arg->philo_num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			philo[i].last_eat_time = get_time();
			ph_thread(&philo[i]);	// 상태값 받아주고, 그걸로 죽는지 체크해야한다.
			return (0);
		}
		i++;
	}
	ph_check_finish(arg, philo);
	// printf("clear\n");
	i = 0;
	while (i < arg->philo_num)
		kill(philo[i++].pid, -1);
		// pthread_join(philo[i++].thread, NULL);
	exit(0);
	waitpid(-1, NULL, 0);
	return (0);
}

void	*ph_thread(void *argv)
{
	t_arg		*arg;
	t_philo		*philo;

	philo = argv;
	arg = philo->arg;
	while (!arg->finish)
	{
		if (arg->philo_num - 1 == philo->id && philo->eat_count == 0)
			usleep(1);
		ph_action(arg, philo);
		if (arg->philo_num == 1)
			spend_time((long long)arg->time_to_sleep, arg);
		if (arg->eat_times == philo->eat_count)
		{
			arg->finished_eat++;
			break ;
		}
		ph_stat_printf(arg, philo->id, "is sleeping");
		spend_time((long long)arg->time_to_sleep, arg);
		ph_stat_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

int	ph_action(t_arg *arg, t_philo *philo)
{
	sem_wait(arg->forks);
	ph_stat_printf(arg, philo->id, "has taken a fork");
	if (arg->philo_num != 1)
	{
		sem_wait(arg->forks);
		ph_stat_printf(arg, philo->id, "has taken a fork");
		ph_stat_printf(arg, philo->id, "is eating");
		philo->last_eat_time = get_time();
		philo->eat_count = philo->eat_count + 1;
		spend_time((long long)arg->time_to_eat, arg);
		sem_post(arg->forks);
	}
	sem_post(arg->forks);
	return (0);
}

void	ph_check_finish(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	while (!arg->finish)
	{
		if ((arg->eat_times != 0) && (arg->philo_num == arg->finished_eat))
		{
			arg->finish = 1;
			break ;
		}
		i = 0;
		while (i < arg->philo_num)
		{
			now = get_time();
			if ((now - philo[i].last_eat_time) >= arg->time_to_die)
			{
				ph_stat_printf(arg, i, "died");
				arg->finish = 1;
				sem_post(arg->print);
				break ;
			}
			i++;
		}
	}
}
