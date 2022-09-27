/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:15:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/27 19:54:42 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] && i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (us1[i] == '\0' && i < n)
		return (us1[i] - us2[i]);
	return (0);
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

long long	get_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (-1);
	return ((mytime.tv_sec * 1000) + (mytime.tv_usec / 1000));
}

void	spend_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = get_time();
	while (!(arg->finish))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}

void	sleep_until_even_eat(t_arg *arg)
{
	struct timeval	get_time;
	struct timeval	timestamp;
	int				time_taken;

	gettimeofday(&get_time, NULL);
	while (1)
	{
		gettimeofday(&timestamp, NULL);
		time_taken = timestamp.tv_usec - get_time.tv_usec + \
			(timestamp.tv_sec - get_time.tv_sec) * 1000000;
		if (time_taken > arg->time_to_eat * 900)
			break ;
		usleep(arg->time_to_eat);
	}
}
