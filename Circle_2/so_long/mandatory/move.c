/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:10:56 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/14 21:27:16 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_w(t_map *map)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'P')
			break ;
	}
	if (map->map_line[i - map->col] == 'C')
		map->item_cnt++;
	if (map->map_line[i - map->col] == 'E' && map->all_item == map->item_cnt)
		exit_game(map);
	else if (map->map_line[i - map->col] != '1' && map->map_line[i - map->col] != 'E')
	{
		map->map_line[i] = '0';
		map->map_line[i - map->col] = 'P';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}

void	move_a(t_map *map)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'P')
			break ;
	}
	if (map->map_line[i - 1] == 'C')
		map->item_cnt++;
	if (map->map_line[i - 1] == 'E' && map->all_item == map->item_cnt)
		exit_game(map);
	else if (map->map_line[i - 1] != '1' && map->map_line[i - 1] != 'E')
	{
		map->map_line[i] = '0';
		map->map_line[i - 1] = 'P';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}

void	move_s(t_map *map)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'P')
			break ;
	}
	if (map->map_line[i + map->col] == 'C')
		map->item_cnt++;
	if (map->map_line[i + map->col] == 'E' && map->all_item == map->item_cnt)
		exit_game(map);
	else if (map->map_line[i + map->col] != '1' && map->map_line[i + map->col] != 'E')
	{
		map->map_line[i] = '0';
		map->map_line[i + map->col] = 'P';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}

void	move_d(t_map *map)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'P')
			break ;
	}
	if (map->map_line[i + 1] == 'C')
		map->item_cnt++;
	if (map->map_line[i + 1] == 'E' && map->all_item == map->item_cnt)
		exit_game(map);
	else if (map->map_line[i + 1] != '1' && map->map_line[i + 1] != 'E')
	{
		map->map_line[i] = '0';
		map->map_line[i + 1] = 'P';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}
