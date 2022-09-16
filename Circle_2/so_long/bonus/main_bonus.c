/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:57:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/16 15:14:24 by chanwjeo         ###   ########.fr       */
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

void	valid_num_of_objs(t_map *map)
{
	int	idx;
	int	c_cnt;
	int	e_cnt;
	int	p_cnt;

	idx = 0;
	c_cnt = 0;
	e_cnt = 0;
	p_cnt = 0;
	while (map->map_line[idx])
	{
		if (map->map_line[idx] == 'C')
			c_cnt++;
		else if (map->map_line[idx] == 'E')
			e_cnt++;
		else if (map->map_line[idx] == 'P')
			p_cnt++;
		idx++;
	}
	map->all_item = c_cnt;
	if (c_cnt < 1 || e_cnt < 1 || p_cnt != 1)
		print_err("map error\n");
}

static void	valid_args(char *av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	if (ft_strncmp(av + i - 4, ".ber", 4) != 0)
		print_err("not valid extension\n");
}

void	put_img_tree(t_map *map, void *ch, int w64, int h64)
{
	put_img(map, map->obj->ld, w64, h64);
	put_img(map, ch, w64, h64);
}

// int	ft_sprite(t_map *map)
// {
// 	int i;
	
// 	i = 0;
// 	while (i < 10000)
// 	{
// 		if ((i / 20) % 2 == 0)
// 			put_img_tree(map, map->obj->tr1, 0, 0);
// 		else
// 			put_img_tree(map, map->obj->tr, 0, 0);
// 		i++;
// 	}
// 	// sleep(1);
// 	// draw_map(map);
// 	// draw_collect(map);
// 	// event_checker(map);
// 	// enemy_script(map);
// 	// draw_sprites(map);
// 	// draw_step_count(map);
// 	// frame_cunt(map);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_map		map;

	if (ac != 2)
		print_err("argument error: ./so_long <map_name>.ber\n");
	ft_memset(&map, 0, sizeof(t_map));
	valid_args(av[1]);
	map_checker(&map, av[1]);
	valid_num_of_objs(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.col * 64, map.row * 64, "so_long");
	obj_init(&map);
	setting_img(&map);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &press_key, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
	// mlx_loop_hook(map.mlx, &ft_sprite, &map);
	mlx_loop(map.mlx);
	return (0);
}
