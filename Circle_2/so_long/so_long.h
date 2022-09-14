/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:58:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/30 13:11:06 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "./mlx/mlx.h"

# define BUFFER_SIZE				1024
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_param
{
	int		x;
	int		y;
}				t_param;

typedef struct	s_map
{
	int				row;
	int				col;
	char			*map_line;
}				t_map;


typedef struct s_obj_data
{
	int		i_w;
	int		i_h;
	void	*land;
	void	*tree;
	void	*item;
	void	*c_d;
	void	*o_d;
	void	*cha1;
	void	*cha2;
	void	*cha3;
	void	*cha4;
	void	*cha5;
	void	*cha6;
	void	*cha7;
}				t_obj_data;

/* utils.c */
void	print_err(char *message);
char	*ft_strdup_without_newline(char *s);
int		ft_strlcpy_without_newline(char *dst, char *src, int len);
char	*ft_strjoin_without_newline(char *s1, char *s2);

/* map_checker.c */
int		first_line_checker(char *line, t_map *map);
void	middle_line_checker(char *line, int col, t_map *map);
int		last_line_checker(char *line, int col, t_map *map);
int		map_size_checker(int fd, t_map *map);
void	map_checker(t_map *map);

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
char	*ft_strjoin(char *s1, char *s2);
int		gnl_strchr(char *s);
int		ft_strlen(const char *s);

#endif
