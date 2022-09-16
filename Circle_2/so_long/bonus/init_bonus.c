/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/16 13:13:38 by chanwjeo         ###   ########.fr       */
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
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->s2 = mlx_xpm_file_to_image(map->mlx, "./img/s2.xpm", &wd, &hg);
	map->obj->s3 = mlx_xpm_file_to_image(map->mlx, "./img/s3.xpm", &wd, &hg);
	map->obj->s4 = mlx_xpm_file_to_image(map->mlx, "./img/s4.xpm", &wd, &hg);
	map->obj->s5 = mlx_xpm_file_to_image(map->mlx, "./img/s5.xpm", &wd, &hg);
	map->obj->s6 = mlx_xpm_file_to_image(map->mlx, "./img/s6.xpm", &wd, &hg);
	obj_init_2(map);
}

void	obj_init_2(t_map *map)
{
	int	wd;
	int	hg;

	map->obj->s7 = mlx_xpm_file_to_image(map->mlx, "./img/s7.xpm", &wd, &hg);
	map->obj->s8 = mlx_xpm_file_to_image(map->mlx, "./img/s8.xpm", &wd, &hg);
	map->obj->s9 = mlx_xpm_file_to_image(map->mlx, "./img/s9.xpm", &wd, &hg);
	map->obj->s10 = mlx_xpm_file_to_image(map->mlx, "./img/s10.xpm", &wd, &hg);
	map->obj->s11 = mlx_xpm_file_to_image(map->mlx, "./img/s11.xpm", &wd, &hg);
	map->obj->s12 = mlx_xpm_file_to_image(map->mlx, "./img/s12.xpm", &wd, &hg);
	map->enm->t1 = mlx_xpm_file_to_image(map->mlx, "./img/t1.xpm", &wd, &hg);
	map->enm->t2 = mlx_xpm_file_to_image(map->mlx, "./img/t2.xpm", &wd, &hg);
	map->enm->t3 = mlx_xpm_file_to_image(map->mlx, "./img/t3.xpm", &wd, &hg);
	map->enm->t4 = mlx_xpm_file_to_image(map->mlx, "./img/t4.xpm", &wd, &hg);
	map->enm->t5 = mlx_xpm_file_to_image(map->mlx, "./img/t5.xpm", &wd, &hg);
	map->enm->t6 = mlx_xpm_file_to_image(map->mlx, "./img/t6.xpm", &wd, &hg);
	map->enm->t7 = mlx_xpm_file_to_image(map->mlx, "./img/t7.xpm", &wd, &hg);
	map->enm->t8 = mlx_xpm_file_to_image(map->mlx, "./img/t8.xpm", &wd, &hg);
	map->enm->t9 = mlx_xpm_file_to_image(map->mlx, "./img/t9.xpm", &wd, &hg);
	map->enm->t10 = mlx_xpm_file_to_image(map->mlx, "./img/t10.xpm", &wd, &hg);
	map->enm->t11 = mlx_xpm_file_to_image(map->mlx, "./img/t11.xpm", &wd, &hg);
	map->enm->t12 = mlx_xpm_file_to_image(map->mlx, "./img/t12.xpm", &wd, &hg);
}
