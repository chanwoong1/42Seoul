/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/09 15:17:39 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac != 2 || ac != 3)
		return (0);
	if (!is_valid_map(av[1]))
		
}
