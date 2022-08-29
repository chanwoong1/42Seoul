/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:57:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/29 23:33:06 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

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

int	first_or_last_line_checker(char *line)
{
	int	col;

	printf("line : %s\n", line);
	col = 0;
	while (line[col])
	{
		if (line[col] != 1)
			return (-1);
		col++;
	}
	printf("col : %d\n", col);
	return (col);
}

void	middle_line_checker(char *line, int col)
{
	int	line_idx;

	line_idx = ft_strlen(line);
	if (line_idx != col)
		print_err("map error\n");
	if (line[0] != 1 || line[col - 1] != 1)
		print_err("map error\n");
}

void	map_checker()
{
	int		fd;
	int		col;
	char	*line;

	fd = open("./map.ber", O_RDONLY);
	line = get_next_line(fd);
	if ((col = first_or_last_line_checker(line)) == -1)
		print_err("map error\n");
	free(line);
	line = get_next_line(fd);
	while (first_or_last_line_checker(line) == -1)
	{
		middle_line_checker(line, col);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if ((line = get_next_line(fd)) != NULL)
		print_err("map error\n");
}

int main()
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	void *img8;
	void *img9;
	void *img10;
	void *img11;
	void *img12;
	int img_width;
	int img_height;
	t_param		param;

	map_checker();
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 500, "so_long");
	// img = mlx_xpm_file_to_image(mlx, "./images/grass.xpm", &img_width, &img_height);
	// img2 = mlx_xpm_file_to_image(mlx, "./images/tree.xpm", &img_width, &img_height);
	// img3 = mlx_xpm_file_to_image(mlx, "./images/item.xpm", &img_width, &img_height);
	// img4 = mlx_xpm_file_to_image(mlx, "./images/closed_door.xpm", &img_width, &img_height);
	// img5 = mlx_xpm_file_to_image(mlx, "./images/opened_door.xpm", &img_width, &img_height);
	// img6 = mlx_xpm_file_to_image(mlx, "./images/character.xpm", &img_width, &img_height);
	// img7 = mlx_xpm_file_to_image(mlx, "./images/character_walk1.xpm", &img_width, &img_height);
	// img8 = mlx_xpm_file_to_image(mlx, "./images/character_walk2.xpm", &img_width, &img_height);
	// img9 = mlx_xpm_file_to_image(mlx, "./images/character_walk3.xpm", &img_width, &img_height);
	// img10 = mlx_xpm_file_to_image(mlx, "./images/character_walk4.xpm", &img_width, &img_height);
	// img11 = mlx_xpm_file_to_image(mlx, "./images/character_walk5.xpm", &img_width, &img_height);
	// img12 = mlx_xpm_file_to_image(mlx, "./images/character_walk6.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(mlx, win, img, 0, 0);
	// mlx_put_image_to_window(mlx, win, img2, 64, 0);
	// mlx_put_image_to_window(mlx, win, img3, 128, 0);
	// mlx_put_image_to_window(mlx, win, img4, 192, 0);
	// mlx_put_image_to_window(mlx, win, img5, 256, 0);
	// mlx_put_image_to_window(mlx, win, img6, 320, 0);
	// mlx_put_image_to_window(mlx, win, img7, 0, 64);
	// mlx_put_image_to_window(mlx, win, img8, 64, 64);
	// mlx_put_image_to_window(mlx, win, img9, 128, 64);
	// mlx_put_image_to_window(mlx, win, img10, 192, 64);
	// mlx_put_image_to_window(mlx, win, img11, 256, 64);
	// mlx_put_image_to_window(mlx, win, img12, 320, 64);
	// mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	// mlx_loop(mlx);
	return (0);
}
