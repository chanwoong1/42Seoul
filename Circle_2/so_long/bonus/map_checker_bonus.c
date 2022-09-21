/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:04:04 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/21 12:34:11 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	first_line_checker(char *line, t_map *map)
{
	int	col;
	int	size;

	size = ft_strlen(line);
	if (size <= 3)
		print_err("map error : not valid your map, check column!\n");
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
		print_err("map error : not valid your map, check middle line!\n");
	idx = -1;
	while (++idx < col - 1)
	{
		if (line[col] != '1')
			break ;
	}
	if (idx == col - 1)
		print_err("map error : not valid your map, check middle line!\n");
	if (first_line_checker(line, map) != -1)
		print_err("map error : not valid your map, check middle line!\n");
	map->map_line = ft_strjoin_without_newline(map->map_line, line);
}

int	last_line_checker(char *line, int col, t_map *map)
{
	int		idx;
	int		size;

	size = ft_strlen(line);
	idx = 0;
	if (col != size)
		print_err("map error : not valid your map, check last line!\n");
	while (idx < size - 1)
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

	if (fd < 0)
		print_err("map error : not valid file descriptor, check your map!\n");
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
	map->row = size - 1;
	if (map->row <= 2)
		print_err("map error : not valid your map size, check your map!\n");
	return (size - 3);
}

void	map_checker(t_map *map, char *av)
{
	int		fd;
	int		col;
	char	*line;
	int		map_size;

	fd = open(av, O_RDONLY);
	map_size = map_size_checker(fd, map);
	close(fd);
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	col = first_line_checker(line, map);
	if (col == -1)
		print_err("map error : not valid your map, check first line!\n");
	free(line);
	while (map_size--)
	{
		line = get_next_line(fd);
		middle_line_checker(line, col, map);
		free(line);
	}
	line = get_next_line(fd);
	if (last_line_checker(line, col, map) == -1)
		print_err("map error : not valid your map, check last line!\n");
	free(line);
	close(fd);
}
