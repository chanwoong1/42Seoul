/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 10:02:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	obj_init(t_map *map)
{
	int	wd;
	int	hg;

	map->x = 3;
	map->y = 4;
	map->obj = (t_obj *)malloc(sizeof(t_obj));
	map->enm = (t_enm *)malloc(sizeof(t_enm));
	if (!map->obj || !map->enm)
		print_err("malloc fail\n");
	map->obj->ld = mlx_xpm_file_to_image(map->mlx, "./img/ld.xpm", &wd, &hg);
	map->obj->tr = mlx_xpm_file_to_image(map->mlx, "./img/tr.xpm", &wd, &hg);
	map->obj->tr1 = mlx_xpm_file_to_image(map->mlx, "./img/tr1.xpm", &wd, &hg);
	map->obj->it = mlx_xpm_file_to_image(map->mlx, "./img/it.xpm", &wd, &hg);
	map->obj->d1 = mlx_xpm_file_to_image(map->mlx, "./img/d1.xpm", &wd, &hg);
	map->obj->d2 = mlx_xpm_file_to_image(map->mlx, "./img/d2.xpm", &wd, &hg);
	map->obj->ss[0].pt = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->ss[1].pt = mlx_xpm_file_to_image(map->mlx, "./img/s2.xpm", &wd, &hg);
	map->obj->ss[2].pt = mlx_xpm_file_to_image(map->mlx, "./img/s3.xpm", &wd, &hg);
	map->obj->sa[0].pt = mlx_xpm_file_to_image(map->mlx, "./img/s4.xpm", &wd, &hg);
	map->obj->sa[1].pt = mlx_xpm_file_to_image(map->mlx, "./img/s5.xpm", &wd, &hg);
	map->obj->sa[2].pt = mlx_xpm_file_to_image(map->mlx, "./img/s6.xpm", &wd, &hg);
	obj_init_2(map);
}

void	obj_init_2(t_map *map)
{
	int	wd;
	int	hg;

	map->obj->sd[0].pt = mlx_xpm_file_to_image(map->mlx, "./img/s7.xpm", &wd, &hg);
	map->obj->sd[1].pt = mlx_xpm_file_to_image(map->mlx, "./img/s8.xpm", &wd, &hg);
	map->obj->sd[2].pt = mlx_xpm_file_to_image(map->mlx, "./img/s9.xpm", &wd, &hg);
	map->obj->sw[0].pt = mlx_xpm_file_to_image(map->mlx, "./img/s10.xpm", &wd, &hg);
	map->obj->sw[1].pt = mlx_xpm_file_to_image(map->mlx, "./img/s11.xpm", &wd, &hg);
	map->obj->sw[2].pt = mlx_xpm_file_to_image(map->mlx, "./img/s12.xpm", &wd, &hg);
	map->obj->tt[0].pt = mlx_xpm_file_to_image(map->mlx, "./img/t1.xpm", &wd, &hg);
	map->obj->tt[1].pt = mlx_xpm_file_to_image(map->mlx, "./img/t2.xpm", &wd, &hg);
	map->obj->tt[2].pt = mlx_xpm_file_to_image(map->mlx, "./img/t3.xpm", &wd, &hg);
	map->obj->tt[3].pt = mlx_xpm_file_to_image(map->mlx, "./img/t4.xpm", &wd, &hg);
	map->obj->tt[4].pt = mlx_xpm_file_to_image(map->mlx, "./img/t5.xpm", &wd, &hg);
	map->obj->tt[5].pt = mlx_xpm_file_to_image(map->mlx, "./img/t6.xpm", &wd, &hg);
	map->obj->tt[6].pt = mlx_xpm_file_to_image(map->mlx, "./img/t7.xpm", &wd, &hg);
	map->obj->tt[7].pt = mlx_xpm_file_to_image(map->mlx, "./img/t8.xpm", &wd, &hg);
	map->obj->tt[8].pt = mlx_xpm_file_to_image(map->mlx, "./img/t9.xpm", &wd, &hg);
	map->obj->tt[9].pt = mlx_xpm_file_to_image(map->mlx, "./img/t10.xpm", &wd, &hg);
	map->obj->tt[10].pt = mlx_xpm_file_to_image(map->mlx, "./img/t11.xpm", &wd, &hg);
	map->obj->tt[11].pt = mlx_xpm_file_to_image(map->mlx, "./img/t12.xpm", &wd, &hg);
}
