/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:57:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/14 19:31:18 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		exit_game(map);
	if (key_code == KEY_W)
		move_w(map);
	// if (key_code == KEY_A)
	// 	move_a(map);
	// if (key_code == KEY_S)
	// 	move_s(map);
	// if (key_code == KEY_D)
	// 	move_d(map);
	printf("x: %d, y: %d\n", map->x, map->y);
	return (0);
}

void	move_w(t_map *map)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'P')
			break ;
	}
	if (map->map_line[i - map->col] == 'C')
		map->col_cnt++;
	if (map->map_line[i - map->col] == 'E' && map->all_col == map->col_cnt)
		exit_game(map);
	else if (map->map_line[i - map->col] != '1' && map->map_line[i - map->col] != 'E')
	{
		map->map_line[i] = '0';
		map->map_line[i - map->col] = 'P';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}

void	setting_img(t_map *map)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			if (map->map_line[hei * map->col + wid] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->obj->tr, wid * 64, hei * 64);
			else if (map->map_line[hei * map->col + wid] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->obj->ld, wid * 64, hei * 64);
				mlx_put_image_to_window(map->mlx, map->win, map->obj->it, wid * 64, hei * 64);
			}
			else if (map->map_line[hei * map->col + wid] == 'P')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->obj->ld, wid * 64, hei * 64);
				mlx_put_image_to_window(map->mlx, map->win, map->obj->c1, wid * 64 + 16, hei * 64 + 16);
			}
			else if (map->map_line[hei * map->col + wid] == 'E')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->obj->ld, wid * 64, hei * 64);
				mlx_put_image_to_window(map->mlx, map->win, map->obj->d1, wid * 64 + 16, hei * 64 + 16);
			}
			else
				mlx_put_image_to_window(map->mlx, map->win, map->obj->ld, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}

int main(void)
{
	t_map		map;

	ft_memset(&map, 0, sizeof(t_map));
	map_checker(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.col * 64, map.row *64, "so_long");
	obj_init(&map);
	setting_img(&map);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &press_key, &map);
	mlx_loop(map.mlx);
	return (0);
}
