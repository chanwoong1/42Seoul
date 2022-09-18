/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:47:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 10:29:56 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_a(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'P')
			break ;
	if (map->map_line[i - 1] == 'C')
		map->item_cnt++;
	if (map->map_line[i - 1] == 'T' || \
		(map->map_line[i - 1] == 'E' && map->all_item == map->item_cnt))
		exit_game(map);
	else if (map->map_line[i - 1] != '1' && \
			map->map_line[i - 1] != 'E')
	{
		move_a3(map, i);
		move_a2(map);
	}
	else if (map->map_line[i - 1] == '1' && \
			map->map_line[i - 1] != 'E')
	{
		if (map->char_row == 0)
			return ;
		move_a2(map);
	}
}

void	move_a2(t_map *map)
{
	map->walk_cnt++;
	move_enemy(map);
	setting_img_a(map);
	if (!ft_strchr(map->map_line, 'P'))
		exit_game(map);
}

void	move_a3(t_map *map, int i)
{
	if (map->char_row == 0)
	{
		map->map_line[i - 1] = 'P';
		map->map_line[i] = '0';
		map->char_row = 64;
	}
}

static void	setting_img_a2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	if (map->map_line[hei * map->col + wid] == '1')
		put_img(map, map->obj->tr1, w64, h64);
	else if (map->map_line[hei * map->col + wid] == '0' && \
			!(map->map_line[hei * map->col + wid - 1] == 'P'))
		put_img(map, map->obj->ld, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'C')
		put_img_c(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'P')
		put_img_char_a(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'T')
		put_img_enm(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'E')
	{
		put_img(map, map->obj->ld, w64, h64);
		if (map->item_cnt == map->all_item)
			put_img(map, map->obj->d2, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->d1, w64 + 16, h64 + 16);
	}
}

void	setting_img_a(t_map *map)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			setting_img_a2(map, hei, wid);
			mlx_string_put (map->mlx, map->win, map->col * 64 - 32, 8, \
					create_trgb(0, 255, 255, 255), ft_itoa(map->walk_cnt));
			wid++;
		}
		hei++;
	}
}
