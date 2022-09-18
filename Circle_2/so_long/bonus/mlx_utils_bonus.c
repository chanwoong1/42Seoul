/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:39:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 20:54:02 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	setting_img(t_map *map)
{
	int		hei;
	int		wid;

	hei = 0;
	map->char_col = 16;
	map->char_row = 16;
	map->enm_walk = 16;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			setting_img_2(map, hei, wid);
			mlx_string_put (map->mlx, map->win, map->col * 64 - 32, 8, \
					create_trgb(0, 255, 255, 255), ft_itoa(map->walk_cnt));
			wid++;
		}
		hei++;
	}
}

void	setting_img_2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	if (map->map_line[hei * map->col + wid] == '1')
		put_img(map, map->obj->tree[0].pt, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'C')
		put_img_c(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'P')
		put_img_char(map, map->obj->ss[0].pt, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'T')
		put_img_char(map, map->obj->tt[0].pt, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'E')
	{
		put_img(map, map->obj->land[0].pt, w64, h64);
		if (map->item_cnt == map->all_item)
			put_img(map, map->obj->door[1].pt, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->door[0].pt, w64 + 16, h64 + 16);
	}
	else
		put_img(map, map->obj->land[0].pt, w64, h64);
}

void	put_img(t_map *map, void *w, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, w, x, y);
}

void	put_img_c(t_map *map, int w64, int h64)
{
	put_img(map, map->obj->land[0].pt, w64, h64);
	put_img(map, map->obj->item[0].pt, w64, h64);
}

void	put_img_char(t_map *map, void *ch, int w64, int h64)
{
	put_img(map, map->obj->land[0].pt, w64, h64);
	put_img(map, ch, w64 + 16, h64 + 16);
}
