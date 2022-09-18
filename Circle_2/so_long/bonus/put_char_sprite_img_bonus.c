/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_sprite_img_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:06:02 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 10:19:29 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_img_char_w(t_map *map, int w64, int h64)
{
	int	i;

	map->char_col = map->char_col - 4;
	i = map->char_col % 3;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64, h64 + 64);
	put_img(map, map->obj->sw[i].pt, w64 + map->char_row, h64 + map->char_col);
}

void	put_img_char_s(t_map *map, int w64, int h64)
{
	int	i;

	map->char_col = map->char_col + 4;
	i = map->char_col % 3;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64, h64 + 64);
	put_img(map, map->obj->ss[i].pt, w64 + map->char_row, h64 + map->char_col);
}

void	put_img_char_a(t_map *map, int w64, int h64)
{
	int	i;

	map->char_row = map->char_row - 4;
	i = map->char_row % 3;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64 + 64, h64);
	put_img(map, map->obj->sa[i].pt, w64 + map->char_row, h64 + map->char_col);
}

void	put_img_char_d(t_map *map, int w64, int h64)
{
	int	i;

	map->char_row = map->char_row + 4;
	i = map->char_row % 3;
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, map->obj->ld, w64 + 64, h64);
	put_img(map, map->obj->sd[i].pt, w64 + map->char_row, h64 + map->char_col);
}
