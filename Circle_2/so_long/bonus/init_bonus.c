/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 20:54:15 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_img(t_map *map, t_img *a, int i, char *xpm)
{
	int	wd;
	int	hg;

	a[i].pt = mlx_xpm_file_to_image(map->mlx, xpm, &wd, &hg);
}

void	obj_init(t_map *map)
{
	map->x = 3;
	map->y = 4;
	map->obj = (t_obj *)malloc(sizeof(t_obj));
	map->enm = (t_enm *)malloc(sizeof(t_enm));
	if (!map->obj || !map->enm)
		print_err("malloc fail\n");
	init_img(map, map->obj->land, 0, "./img/ld.xpm");
	init_img(map, map->obj->land, 1, "./img/ld1.xpm");
	init_img(map, map->obj->land, 2, "./img/ld2.xpm");
	init_img(map, map->obj->land, 3, "./img/ld3.xpm");
	init_img(map, map->obj->tree, 0, "./img/tr1.xpm");
	init_img(map, map->obj->tree, 1, "./img/tr2.xpm");
	init_img(map, map->obj->tree, 2, "./img/tr3.xpm");
	init_img(map, map->obj->tree, 3, "./img/tr4.xpm");
	init_img(map, map->obj->item, 0, "./img/it.xpm");
	init_img(map, map->obj->door, 0, "./img/d1.xpm");
	init_img(map, map->obj->door, 1, "./img/d2.xpm");
	init_img(map, map->obj->ss, 0, "./img/s1.xpm");
	init_img(map, map->obj->ss, 1, "./img/s2.xpm");
	init_img(map, map->obj->ss, 2, "./img/s3.xpm");
	init_img(map, map->obj->sa, 0, "./img/s4.xpm");
	init_img(map, map->obj->sa, 1, "./img/s5.xpm");
	init_img(map, map->obj->sa, 2, "./img/s6.xpm");
	obj_init_2(map);
}

void	obj_init_2(t_map *map)
{
	init_img(map, map->obj->sd, 0, "./img/s7.xpm");
	init_img(map, map->obj->sd, 1, "./img/s8.xpm");
	init_img(map, map->obj->sd, 2, "./img/s9.xpm");
	init_img(map, map->obj->sw, 0, "./img/s10.xpm");
	init_img(map, map->obj->sw, 1, "./img/s11.xpm");
	init_img(map, map->obj->sw, 2, "./img/s12.xpm");
	init_img(map, map->obj->tt, 0, "./img/t1.xpm");
	init_img(map, map->obj->tt, 1, "./img/t2.xpm");
	init_img(map, map->obj->tt, 2, "./img/t3.xpm");
	init_img(map, map->obj->tt, 3, "./img/t4.xpm");
	init_img(map, map->obj->tt, 4, "./img/t5.xpm");
	init_img(map, map->obj->tt, 5, "./img/t6.xpm");
	init_img(map, map->obj->tt, 6, "./img/t7.xpm");
	init_img(map, map->obj->tt, 7, "./img/t8.xpm");
	init_img(map, map->obj->tt, 8, "./img/t9.xpm");
	init_img(map, map->obj->tt, 9, "./img/t10.xpm");
	init_img(map, map->obj->tt, 10, "./img/t11.xpm");
	init_img(map, map->obj->tt, 11, "./img/t12.xpm");
}
