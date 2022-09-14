/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:57:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/30 13:12:21 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

void	obj_init(t_obj_data *obj, void **mlx)
{
	int	width;
	int	height;

	obj->land = mlx_xpm_file_to_image(*mlx, "./img/land.xpm", &width, &height);
	obj->tree = mlx_xpm_file_to_image(*mlx, "./img/tree.xpm", &width, &height);
	obj->item = mlx_xpm_file_to_image(*mlx, "./img/item.xpm", &width, &height);
	obj->c_d = mlx_xpm_file_to_image(*mlx, "./img/c_d.xpm", &width, &height);
	obj->o_d = mlx_xpm_file_to_image(*mlx, "./img/o_d.xpm", &width, &height);
	obj->cha1 = mlx_xpm_file_to_image(*mlx, "./img/character.xpm", &width, &height);
	obj->cha2 = mlx_xpm_file_to_image(*mlx, "./img/character_walk1.xpm", &width, &height);
	obj->cha3 = mlx_xpm_file_to_image(*mlx, "./img/character_walk2.xpm", &width, &height);
	obj->cha4 = mlx_xpm_file_to_image(*mlx, "./img/character_walk3.xpm", &width, &height);
	obj->cha5 = mlx_xpm_file_to_image(*mlx, "./img/character_walk4.xpm", &width, &height);
	obj->cha6 = mlx_xpm_file_to_image(*mlx, "./img/character_walk5.xpm", &width, &height);
	obj->cha7 = mlx_xpm_file_to_image(*mlx, "./img/character_walk6.xpm", &width, &height);
}

// void	setting_img()
// {
// 	int		hei;
// 	int		wid;

// 	hei = 0;
// 	while (hei < game.height)
// 	{
// 		wid = 0;
// 		while (wid < game.width)
// 		{
// 			if (game.str_line[hei * game.width + wid] == '1')
// 			{
// 				mlx_put_image_to_window(game.mlx, game.win, game.img.wall, wid * 64, hei * 64);
// 			}
// 			else if (game.str_line[hei * game.width + wid] == 'C')
// 			{
// 				mlx_put_image_to_window(game.mlx, game.win, game.img.chest, wid * 64, hei * 64);
// 			}
// 			else if (game.str_line[hei * game.width + wid] == 'P')
// 			{
// 				mlx_put_image_to_window(game.mlx, game.win, game.img.chara, wid * 64, hei * 64);
// 			}
// 			else if (game.str_line[hei * game.width + wid] == 'E')
// 			{
// 				mlx_put_image_to_window(game.mlx, game.win, game.img.rune, wid * 64, hei * 64);
// 			}
// 			else
// 			{
// 				mlx_put_image_to_window(game.mlx, game.win, game.img.land, wid * 64, hei * 64);
// 			}
// 			wid++;
// 		}
// 		hei++;
// 	}
// }

int main()
{
	void 		*mlx;
	void 		*win;
	t_map		map;
	t_param		param;
	t_obj_data	obj;

	map_checker(&map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");
	obj_init(&obj, &mlx);
	printf("map->row, map->col : %d, %d\n", (&map)->row, (&map)->col);
	printf("map->map_line : %s\n", (&map)->map_line);
	mlx_put_image_to_window(mlx, win, obj.land, 0, 0);
	mlx_put_image_to_window(mlx, win, obj.tree, 64, 0);
	mlx_put_image_to_window(mlx, win, obj.item, 128, 0);
	mlx_put_image_to_window(mlx, win, obj.c_d, 192, 0);
	mlx_put_image_to_window(mlx, win, obj.o_d, 256, 0);
	mlx_put_image_to_window(mlx, win, obj.cha1, 320, 0);
	mlx_put_image_to_window(mlx, win, obj.cha2, 0, 64);
	mlx_put_image_to_window(mlx, win, obj.cha3, 64, 64);
	mlx_put_image_to_window(mlx, win, obj.cha4, 128, 64);
	mlx_put_image_to_window(mlx, win, obj.cha5, 192, 64);
	mlx_put_image_to_window(mlx, win, obj.cha6, 256, 64);
	mlx_put_image_to_window(mlx, win, obj.cha7, 320, 64);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
	return (0);
}
