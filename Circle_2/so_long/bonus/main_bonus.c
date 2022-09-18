/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:57:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 22:56:38 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	press_key(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		exit_game(map);
	if (key_code == KEY_W)
		move_w(map);
	if (key_code == KEY_A)
		move_a(map);
	if (key_code == KEY_S)
		move_s(map);
	if (key_code == KEY_D)
		move_d(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map		map;

	if (ac != 2)
		print_err("argument error: ./so_long <map_name>.ber\n");
	ft_memset(&map, 0, sizeof(t_map));
	valid_args(av[1]);
	map_checker(&map, av[1]);
	valid_map(&map);
	valid_num_of_objs(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.col * 64, map.row * 64, "so_long");
	obj_init(&map);
	create_enemy(&map);
	setting_img(&map);
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &press_key, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
