/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:55:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 22:58:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	valid_args(char *av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	if (ft_strncmp(av + i - 4, ".ber", 4) != 0)
		print_err("not valid extension\n");
}

void	valid_map(t_map *map)
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
