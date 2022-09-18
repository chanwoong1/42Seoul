/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enm_sprite_img_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:46:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 09:36:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_img_enm(t_map *map, int w64, int h64)
{
	if (map->rand_num == 0)
		put_img_enm_w(map, w64, h64);
	if (map->rand_num == 1)
		put_img_enm_s(map, w64, h64);
	if (map->rand_num == 2)
		put_img_enm_a(map, w64, h64);
	if (map->rand_num == 3)
		put_img_enm_d(map, w64, h64);
}

void	put_img_enm_w(t_map *map, int w64, int h64)
{
	int	i;

	i = map->enm_col % 12;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64, h64 + 64);
	put_img(map, map->obj->tt[i].pt, w64 + map->char_row, h64 + map->char_col);
}

void	put_img_enm_s(t_map *map, int w64, int h64)
{
	int	i;

	i = map->enm_col % 12;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64, h64 + 64);
	put_img(map, map->obj->tt[i].pt, w64 + map->char_row, h64 + map->char_col);
}

void	put_img_enm_a(t_map *map, int w64, int h64)
{
	int	i;

	i = map->enm_col % 12 + 10;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64 - 64, h64);
	put_img(map, map->obj->tt[i].pt, w64 + map->char_row, h64 + map->char_col);
}

void	put_img_enm_d(t_map *map, int w64, int h64)
{
	int	i;

	i = map->enm_col % 12;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64 + 64, h64);
	put_img(map, map->obj->tt[i].pt, w64 + map->char_row, h64 + map->char_col);
}