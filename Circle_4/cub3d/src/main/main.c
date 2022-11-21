/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/21 14:44:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../libft/include/libft.h"

void	error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

void	validate_map(char *map)
{
	int	value_of_map;

	value_of_map = ft_strlen(map);
	if (ft_strncmp(map + value_of_map - 4, ".cub", 4))
		error_exit("Not validate map extension.");
	
}

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		return (0);
	validate_map(av[1]);
	return (0);
}
