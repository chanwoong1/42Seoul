/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/23 15:51:38 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

void	init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->mlx = mlx_init();
	map->texture = malloc(sizeof(t_texture));
}

void	init_img(t_map *map, t_img *a, int i, char *xpm)
{
	int	wd;
	int	hg;

	a[i].pt = mlx_xpm_file_to_image(map->mlx, xpm, &wd, &hg);
}

void	validate_map(t_map *map, char *map_path)
{
	int		value_of_map;

	value_of_map = ft_strlen(map_path);
	if (ft_strncmp(map_path + value_of_map - 4, ".cub", 4))
		error_exit("Not validate map extension.");
	char	**texture_split;
	int		map_fd;
	char	*line;
	texture_split = ft_split("NO,SO,WE,EA", ',');
	if (!texture_split)
		error_exit("Failure memory allocate for split.");
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		error_exit("Failure map open.");
	int i = 0;
	char **line_split;
	char *line_without_newline;
	while (texture_split[i])
	{
		line = get_next_line(map_fd);
		line_split = ft_split(line, ' ');
		line_without_newline = ft_strdup_without_newline(line_split[1]);
		init_img(map, map->texture->textures, i, line_without_newline);
		// map->texture->textures[i] = mlx_xpm_file_to_image(map->mlx, line_without_newline, 0, 0);
		printf("%s\n", line_without_newline);
		i++;
		free(line);
		free_double_array((void **)line_split);
		free(line_without_newline);
	}
	free_double_array((void **)texture_split);
}

int	main(int ac, char **av)
{
	t_map	map;
	
	if (ac != 2 && ac != 3)
		return (0);
	init_map(&map);
	validate_map(&map, av[1]);
	system("leaks cub3d");
	return (0);
}
