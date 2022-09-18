/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:05:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 20:51:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	create_enemy(t_map *map)
{
	int	rand_num;

	while (1)
	{
		rand_num = rand() % ((int)ft_strlen(map->map_line) - 1);
		if (map->map_line[rand_num] == '0')
		{
			map->map_line[rand_num] = 'T';
			return ;
		}
	}
}

void	move_enemy(t_map *map)
{
	int	i;

	i = 0;
	map->enm_walk = map->enm_walk + 8;
	while (i++ < map->map_size)
	{
		if (map->map_line[i] == 'T')
		{
			map->rand_num = rand() % 4;
			if (map->enm_walk == 64)
			{
				if (map->rand_num == 0)
					move_enemy2(map, i, -1 * map->col);
				else if (map->rand_num == 1)
					move_enemy2(map, i, map->col);
				else if (map->rand_num == 2)
					move_enemy2(map, i, -1);
				else
					move_enemy2(map, i, 1);
				map->enm_walk = 0;
			}
			return ;
		}
	}
}

void	move_enemy2(t_map *map, int i, int direction)
{
	if (map->map_line[i + direction] != '1' && \
		map->map_line[i + direction] != 'C' && \
		map->map_line[i + direction] != 'E')
	{
		map->map_line[i] = '0';
		map->map_line[i + direction] = 'T';
	}
}
