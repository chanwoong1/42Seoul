/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:04:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/14 18:57:20 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	first_line_checker(char *line, t_map *map)
{
	int	col;
	int	size;

	size = ft_strlen(line);
	col = 0;
	while (col < size - 1)
	{
		if (line[col] != '1')
			return (-1);
		col++;
	}
	if (line[col] == '\n')
	{
		map->col = col;
		map->map_line = ft_strdup_without_newline(line);
		return (col + 1);
	}
	return (-1);
}

void	middle_line_checker(char *line, int col, t_map *map)
{
	int		line_idx;
	int		idx;

	line_idx = ft_strlen(line);
	if (line_idx != col || (line[0] != '1' || line[col - 2] != '1'))
		print_err("map error\n");
	idx = -1;
	while (++idx < col - 1)
	{
		if (line[col] != '1')
			break ;
	}
	if (idx == col - 1)
		print_err("map error\n");
	if (first_line_checker(line, map) != -1)
		print_err("map error\n");
	map->map_line = ft_strjoin_without_newline(map->map_line, line);
}

int	last_line_checker(char *line, int col, t_map *map)
{
	int		idx;
	int		size;

	size = ft_strlen(line);
	idx = 0;
	if (col - 1 != size)
		print_err("map error\n");
	while (idx < size)
	{
		if (line[idx] != '1')
			return (-1);
		idx++;
	}
	map->map_line = ft_strjoin_without_newline(map->map_line, line);
	return (idx);
}

int	map_size_checker(int fd, t_map *map)
{
	int		size;
	char	*line;

	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (gnl_strchr(line) == -1)
			break ;
		size++;
		free(line);
	}
	size++;
	free(line);
	map->row = size;
	return (size - 2);
}

void	map_checker(t_map *map)
{
	int		fd;
	int		col;
	char	*line;
	int		map_size;

	fd = open("./map.ber", O_RDONLY);
	map_size = map_size_checker(fd, map);
	close(fd);
	fd = open("./map.ber", O_RDONLY);
	line = get_next_line(fd);
	col = first_line_checker(line, map);
	if (col == -1)
		print_err("map error\n");
	free(line);
	while (map_size--)
	{
		line = get_next_line(fd);
		middle_line_checker(line, col, map);
		free(line);
	}
	line = get_next_line(fd);
	if (last_line_checker(line, col, map) == -1)
		print_err("map error\n");
	free(line);
	close(fd);
}
