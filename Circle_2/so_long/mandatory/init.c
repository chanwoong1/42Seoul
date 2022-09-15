/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:09:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/15 14:14:37 by chanwjeo         ###   ########.fr       */
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
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->s4 = mlx_xpm_file_to_image(map->mlx, "./img/s4.xpm", &wd, &hg);
	map->obj->s7 = mlx_xpm_file_to_image(map->mlx, "./img/s7.xpm", &wd, &hg);
	map->obj->s10 = mlx_xpm_file_to_image(map->mlx, "./img/s10.xpm", &wd, &hg);
}
