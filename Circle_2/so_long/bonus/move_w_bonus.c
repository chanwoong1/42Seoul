/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:04:46 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/19 15:30:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	setting_img_w2(t_map *map, int hei, int wid)
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

static void	setting_img_w3(t_map *map)
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
				put_img_char_w(map, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}

void	setting_img_w(t_map *map)
{
	int		hei;
	int		wid;
	char	*walk_cnt;

	hei = 0;
	walk_cnt = ft_itoa(map->walk_cnt);
	if (!walk_cnt)
		return ;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			put_img_land(map, wid * 64, hei * 64);
			setting_img_w2(map, hei, wid);
			wid++;
		}
		hei++;
	}
	setting_img_w3(map);
	mlx_string_put (map->mlx, map->win, map->col * 64 - 32, 8, \
					create_trgb(0, 255, 255, 255), walk_cnt);
	free(walk_cnt);
}

static int	move_w2(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'P')
			break ;
	if (map->char_col == 0)
	{
		if (map->map_line[i - map->col] == '1')
			return (1);
		if (map->map_line[i - map->col] == 'T')
			exit_game(map);
		if (map->map_line[i - map->col] == 'E' && map->item_cnt == 0)
			exit_game(map);
		if (map->map_line[i - map->col] == 'E' && map->item_cnt != 0)
			return (1);
		map->map_line[i - map->col] = 'P';
		map->map_line[i] = '0';
		map->char_col = 64;
	}
	return (0);
}

void	move_w(t_map *map)
{
	int	i;

	i = 0;
	map->item_cnt = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'C')
			map->item_cnt++;
	if (move_w2(map))
		return ;
	map->walk_cnt++;
	move_enemy(map);
	setting_img_w(map);
}
