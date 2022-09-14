/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:58:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/14 19:31:51 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* to mlx */
#include "../mlx/mlx.h"

/* to get_next_line */
#include "../gnl/get_next_line.h"

/* to libft */
#include "../libft/libft.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_obj
{
	int		i_w;
	int		i_h;
	void	*ld;
	void	*tr;
	void	*it;
	void	*d1;
	void	*d2;
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
	void	*c5;
	void	*c6;
	void	*c7;
}				t_obj;

typedef struct		s_map
{
	int				x;
	int				y;
	int				row;
	int				col;
	int				all_col;
	int				row_cnt;
	int				col_cnt;
	int				walk_cnt;
	char			*map_line;
	void			*mlx;
	void			*win;
	struct s_obj	*obj;
}					t_map;
/* main.c */
void	setting_img(t_map *map);
void	move_w(t_map *map);
int		press_key(int key_code, t_map *map);

/* init.c */
void	obj_init(t_map *map);

/* utils.c */
void	exit_game(t_map *game);
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

#endif
