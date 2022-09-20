/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:44:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/19 05:49:30 by chanwjeo         ###   ########.fr       */
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

void	print_index_loop(char *str, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		printf("[%s]i is %d\n", str, i);
		usleep(1000 * 100);
		++i;
	}
}

void	*thread_routine(void *arg)
{
	print_index_loop("thread", 5);
	return (NULL);
}

int 	main()
{
	pthread_t	tid;
	int			create_res;
	int			detach_res;
	int			join_res;

	// [ 1. create new thread in this process ]
	// args:	1.thread(ID)
	//			2.attr(info of new thread, generally filled with NULL)
	//			3.function ptr
	//			4.function's argument
	//			success -> return: 0	// fail -> return: errno
	create_res = pthread_create(&tid, NULL, thread_routine, NULL);
	if (create_res != 0)
		return (1);
	print_index_loop("main", 3);

	// [ 2. detach thread from main thread ]
	// 			success -> return: 0	// fail -> return: errno
	detach_res = pthread_detach(tid);
	printf("detaced result: %d\n", detach_res);


	// [ 3. (join)wait for thread ]
	// args:	1. thread(ID)
	//			2.thread function's return value
	join_res = pthread_join(tid, NULL);
	printf("join result: %d\n", join_res);
	return (0);
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
