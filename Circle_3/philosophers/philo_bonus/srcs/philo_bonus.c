/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoong <chanwoong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:19:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/29 12:55:22 by chanwoong        ###   ########.fr       */
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
	if (!(arg->finish))
		printf("%lld %d %s\n", now - arg->start_time, id + 1, msg);
	if (ft_strncmp(msg, "died", 4) == 0)
		return (0);
	sem_post(arg->print);
	return (0);
}

int	ph_start(t_arg *arg)
{
	int		i;
	int		status;

	i = 0;
	while (i < arg->philo_num)
	{
		arg->philo[i].pid = fork();
		if (arg->philo[i].pid == 0)
		{
			arg->philo[i].last_eat_time = get_time();
			if (ph_thread(&arg->philo[i]))
				return (1);
			return (0);
		}
		i++;
	}
	waitpid(-1, &status, 0);
	if ((status >> 8 & 0xff) == DEAD)
	{
		i = -1;
		while (++i < arg->philo_num)
			kill(arg->philo[i].pid, -1);
	}
	return (0);
}

int	ph_thread(void *argv)
{
	t_arg		*arg;
	t_philo		*philo;

	philo = argv;
	arg = philo->arg;
	if (pthread_create(&(philo->monitor), NULL, ph_check_finish, argv))
		return (1);
	while (!arg->finish)
	{
		ph_action(arg, philo);
		if (arg->philo_num != 1 && arg->eat_times == philo->eat_count)
		{
			arg->finished_eat++;
			break ;
		}
		if (arg->philo_num != 1)
			ph_stat_printf(arg, philo->id, "is sleeping");
		spend_time((long long)arg->time_to_sleep, arg);
		if (arg->philo_num != 1)
			ph_stat_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

int	ph_action(t_arg *arg, t_philo *philo)
{
	sem_wait(arg->forks);
	ph_stat_printf(arg, philo->id, "has taken a fork");
	if (arg->philo_num == 1)
		spend_time((long long)arg->time_to_sleep, arg);
	if (arg->philo_num != 1)
	{
		sem_wait(arg->forks);
		ph_stat_printf(arg, philo->id, "has taken a fork");
		ph_stat_printf(arg, philo->id, "is eating");
		philo->last_eat_time = get_time();
		philo->eat_count = philo->eat_count + 1;
		spend_time((long long)arg->time_to_eat, arg);
		sem_post(arg->forks);
		sem_post(arg->forks);
	}
	return (0);
}

void	*ph_check_finish(void *argv)
{
	long long	now;
	t_arg		*arg;
	t_philo		*philo;

	philo = argv;
	arg = philo->arg;
	while (!arg->finish)
	{
		now = get_time();
		if ((now - philo->last_eat_time) >= arg->time_to_die)
		{
			ph_stat_printf(arg, philo->id, "died");
			arg->finish = 1;
			break ;
		}		
	}
	exit(DEAD);
	return (NULL);
}
