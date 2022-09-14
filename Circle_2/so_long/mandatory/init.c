/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/14 19:18:50 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	obj_init(t_map *map)
{
	int	wd;
	int	hg;

	map->x = 3;
	map->y = 4;
	map->obj = (t_obj *)malloc(sizeof(t_obj));
	if (!map->obj)
		return ;
	map->obj->ld = mlx_xpm_file_to_image(map->mlx, "./img/ld.xpm", &wd, &hg);
	map->obj->tr = mlx_xpm_file_to_image(map->mlx, "./img/tr.xpm", &wd, &hg);
	map->obj->it = mlx_xpm_file_to_image(map->mlx, "./img/it.xpm", &wd, &hg);
	map->obj->d1 = mlx_xpm_file_to_image(map->mlx, "./img/d1.xpm", &wd, &hg);
	map->obj->d2 = mlx_xpm_file_to_image(map->mlx, "./img/d2.xpm", &wd, &hg);
	map->obj->c1 = mlx_xpm_file_to_image(map->mlx, "./img/c1.xpm", &wd, &hg);
	map->obj->c2 = mlx_xpm_file_to_image(map->mlx, "./img/c2.xpm", &wd, &hg);
	map->obj->c3 = mlx_xpm_file_to_image(map->mlx, "./img/c3.xpm", &wd, &hg);
	map->obj->c4 = mlx_xpm_file_to_image(map->mlx, "./img/c4.xpm", &wd, &hg);
	map->obj->c5 = mlx_xpm_file_to_image(map->mlx, "./img/c5.xpm", &wd, &hg);
	map->obj->c6 = mlx_xpm_file_to_image(map->mlx, "./img/c6.xpm", &wd, &hg);
	map->obj->c7 = mlx_xpm_file_to_image(map->mlx, "./img/c7.xpm", &wd, &hg);
}
