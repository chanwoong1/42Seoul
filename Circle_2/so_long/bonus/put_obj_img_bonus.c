/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_obj_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:01:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 20:18:19 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_img_tree(t_map *map, int w64, int h64)
{
	int	i;

	i = (map->char_row + map->char_col) % 3;
	put_img(map, map->obj->tree[i + 1].pt, w64, h64);
}

void	put_img_land(t_map *map, int w64, int h64)
{
	int	i;

	i = (map->char_row + map->char_col) % 3;
	put_img(map, map->obj->land[i + 1].pt, w64, h64);
}
