/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:44:21 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/27 19:56:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	print_error(char *msg)
{
	printf("Error : %s\n", msg);
	return (FAIL);
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (print_error("invalid number of args"));
	memset(&arg, 0, sizeof(t_arg));
	if (init_args(&arg, argc, argv))
		return (print_error("args init fail"));
	if (init_philo(&arg))
		return (print_error("philo init fail"));
	if (ph_start(&arg))
		return (print_error("philo start fail"));
	sem_close(arg.print);
	sem_close(arg.forks);
	return (SUCCESS);
}
