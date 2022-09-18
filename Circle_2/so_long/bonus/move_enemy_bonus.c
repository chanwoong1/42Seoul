/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:05:53 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 09:36:32 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	create_enemy(t_map *map)
{
	int rand_num;

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
	int		rand_num;
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'T')
		{
			rand_num = rand() % 4;
			map->rand_num = rand_num;
			if (rand_num == 0)
				move_enemy_w(map, i, -1 * map->col);
			else if (rand_num == 1)
				move_enemy_s(map, i, map->col);
			else if (rand_num == 2)
				move_enemy2(map, i, -1);
			else
				move_enemy2(map, i, 1);
		}
	}
}

void	move_enemy_w(t_map *map, int i, int direction)
{
	map->enm_col = map->enm_col - 4;
	if (map->map_line[i + direction] != '1' && \
		map->map_line[i + direction] != 'C' && map->enm_col == 0)
	{
		map->map_line[i] = '0';
		map->map_line[i + direction] = 'T';
		map->enm_col = 64;
	}
}

void	move_enemy_s(t_map *map, int i, int direction)
{
	map->enm_col = map->enm_col + 4;
	if (map->map_line[i + direction] != '1' && \
		map->map_line[i + direction] != 'C' && map->enm_col == 64)
	{
		map->map_line[i] = '0';
		map->map_line[i + direction] = 'T';
		map->enm_col = 0;
	}
}

void	move_enemy2(t_map *map, int i, int direction)
{
	if (map->map_line[i + direction] != '1' && \
		map->map_line[i + direction] != 'C')
	{
		map->map_line[i] = '0';
		map->map_line[i + direction] = 'T';
	}
}
