/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enm_sprite_img_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:46:39 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 20:13:53 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_img_enm(t_map *map, int w64, int h64)
{
	int	i;

	i = (map->char_row + map->char_col) % 11;
	put_img(map, map->obj->tt[i].pt, w64 + 16, h64 + 16);
}
