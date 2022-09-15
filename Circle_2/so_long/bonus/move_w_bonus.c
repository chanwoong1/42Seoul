/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:53:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/15 17:13:35 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	if (map->map_line[i - map->col] == 'T' || \
		(map->map_line[i - map->col] == 'E' && map->all_item == map->item_cnt))
		exit_game(map);
	else if (map->map_line[i - map->col] != '1' && \
			map->map_line[i - map->col] != 'E')
	{
		map->map_line[i] = '0';
		map->map_line[i - map->col] = 'P';
		map->walk_cnt++;
		move_enemy(map);
		setting_img_w(map);
		if (!ft_strchr(map->map_line, 'P'))
			exit_game(map);
	}
}

static void	setting_img_w2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	if (map->map_line[hei * map->col + wid] == '1')
		put_img(map, map->obj->tr, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'C')
		put_img_c(map, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'P')
		put_img_char(map, map->obj->s10, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'T')
		put_img_char(map, map->enm->t1, w64, h64);
	else if (map->map_line[hei * map->col + wid] == 'E')
	{
		put_img(map, map->obj->ld, w64, h64);
		if (map->item_cnt == map->all_item)
			put_img(map, map->obj->d2, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->d1, w64 + 16, h64 + 16);
	}
	else
		put_img(map, map->obj->ld, w64, h64);
}

void	setting_img_w(t_map *map)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			setting_img_w2(map, hei, wid);
			mlx_string_put (map->mlx, map->win, map->col * 64 - 32, 8, \
					create_trgb(0, 255, 255, 255), ft_itoa(map->walk_cnt));
			wid++;
		}
		hei++;
	}
}
