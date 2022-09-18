/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:57:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 20:00:18 by chanwjeo         ###   ########.fr       */
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
	int	e_cnt;
	int	p_cnt;

	idx = 0;
	e_cnt = 0;
	p_cnt = 0;
	while (map->map_line[idx])
	{
		if (map->map_line[idx] == 'C')
			map->all_item++;
		else if (map->map_line[idx] == 'E')
			e_cnt++;
		else if (map->map_line[idx] == 'P')
			p_cnt++;
		idx++;
	}
	if (map->all_item < 1 || e_cnt < 1 || p_cnt != 1)
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

static void	valid_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map->map_line))
	{
		if (!(map->map_line[i] == '1' || map->map_line[i] == 'C' || \
			map->map_line[i] == 'P' || map->map_line[i] == 'E' || \
			map->map_line[i] == '0'))
			print_err("map error\n");
		i++;
	}
	map->map_size = ft_strlen(map->map_line);
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
