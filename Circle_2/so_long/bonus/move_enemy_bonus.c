/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:05:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/15 17:06:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_enemy(t_map *map)
{
	int		rand_num;
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'T')
			break ;
	}
	rand_num = rand() % 4;
	if (rand_num == 0)
		move_enemy2(map, i, -1 * map->col);
	else if (rand_num == 1)
		move_enemy2(map, i, map->col);
	else if (rand_num == 2)
		move_enemy2(map, i, -1);
	else
		move_enemy2(map, i, 1);
}

void	move_enemy2(t_map *map, int i, int direction)
{
	if (map->map_line[i + direction] != '1')
	{
		map->map_line[i] = '0';
		map->map_line[i + direction] = 'T';
	}
}
