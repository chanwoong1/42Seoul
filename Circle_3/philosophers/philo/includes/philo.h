/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:29:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/24 20:54:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/errno.h>

# define SUCCESS	1
# define FAIL		0

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
}				t_philo;

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_arg;

/* main.c */
int			print_error(char *msg, int err);
int			ft_atoi(const char *str);
long long	ft_get_time(void);
void		ft_pass_time(long long wait_time, t_arg *arg);

/* init.c */
int			ft_arg_init_mutex(t_arg *arg);
int			ft_arg_init(t_arg *arg, int argc, char **argv);
int			ft_philo_init(t_philo **philo, t_arg *arg);

/* philo.c */
int			ft_philo_printf(t_arg *arg, int id, char *msg);
int			ft_philo_action(t_arg *arg, t_philo *philo);
void		ft_philo_check_finish(t_arg *arg, t_philo *philo);
int			ft_philo_start(t_arg *arg, t_philo *philo);
void		*ft_thread(void *argv);

#endif