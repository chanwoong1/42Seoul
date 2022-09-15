/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:47:52 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/15 16:05:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		ft_putnbr_fd(map->walk_cnt, 1);
		write(1, "\n", 1);
		setting_img_a(map);
	}
}

static void	setting_img_a2(t_map *map, int hei, int wid)
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
		put_img_char(map, map->obj->s4, w64, h64);
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
			wid++;
		}
		hei++;
	}
}
