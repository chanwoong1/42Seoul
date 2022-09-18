/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_d_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:40:34 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 20:16:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	setting_img_d2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	if (map->map_line[hei * map->col + wid] == '1')
		put_img_tree(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'C')
		put_img_c(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'T')
		put_img_enm(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'E')
	{
		if (map->item_cnt == 0)
			put_img(map, map->obj->door[1].pt, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->door[0].pt, w64 + 16, h64 + 16);
	}
}

static void	setting_img_d3(t_map *map)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			if (map->map_line[hei * map->col + wid] == 'P')
				put_img_char_d(map, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}

void	setting_img_d(t_map *map)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			put_img_land(map, wid * 64, hei * 64);
			setting_img_d2(map, hei, wid);
			mlx_string_put (map->mlx, map->win, map->col * 64 - 32, 8, \
					create_trgb(0, 255, 255, 255), ft_itoa(map->walk_cnt));
			wid++;
		}
		hei++;
	}
	setting_img_d3(map);
}

static int	move_d2(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'P')
			break ;
	if (map->char_row == 48)
		if (map->map_line[i + 1] == '1')
			return (1);
	if (map->char_row == 64)
	{
		if (map->map_line[i + 1] == 'T')
			exit_game(map);
		if (map->map_line[i + 1] == 'E' && map->item_cnt == 0)
			exit_game(map);
		if (map->map_line[i + 1] == 'E' && map->item_cnt != 0)
			return (1);
		map->map_line[i + 1] = 'P';
		map->map_line[i] = '0';
		map->char_row = 0;
	}
	return (0);
}

void	move_d(t_map *map)
{
	int	i;

	i = 0;
	map->item_cnt = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'C')
			map->item_cnt++;
	if (move_d2(map))
		return ;
	map->walk_cnt++;
	move_enemy(map);
	setting_img_d(map);
}
