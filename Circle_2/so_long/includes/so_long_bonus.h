/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:58:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/18 10:26:16 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

typedef struct	s_img
{
	void	*pt;
}				t_img;

typedef struct	s_obj
{
	void	*ld;
	void	*tr;
	void	*tr1;
	void	*it;
	void	*d1;
	void	*d2;
	t_img	sw[3];
	t_img	ss[3];
	t_img	sa[3];
	t_img	sd[3];
	t_img	tt[12];
}				t_obj;

typedef struct s_enm
{
	void	*t1;
	void	*t2;
	void	*t3;
	void	*t4;
	void	*t5;
	void	*t6;
	void	*t7;
	void	*t8;
	void	*t9;
	void	*t10;
	void	*t11;
	void	*t12;
}				t_enm;

typedef struct		s_map
{
	int				x;
	int				y;
	int				row;
	int				col;
	int				char_row;
	int				char_col;
	int				enm_row;
	int				enm_col;
	int				all_item;
	int				item_cnt;
	int				walk_cnt;
	int				rand_num;
	int				map_size;
	char			*map_line;
	void			*mlx;
	void			*win;
	struct s_obj	*obj;
	struct s_enm	*enm;
}					t_map;
/* main_bonus.c */
int		create_trgb(int t, int r, int g, int b);
int		press_key(int key_code, t_map *map);
void	put_img_tree(t_map *map, void *ch, int w64, int h64);

/* init_bonus.c */
void	obj_init(t_map *map);
void	obj_init_2(t_map *map);

/* utils_bonus.c */
int		exit_game(t_map *game);
void	print_err(char *message);
char	*ft_strdup_without_newline(char *s);
int		ft_strlcpy_without_newline(char *dst, char *src, int len);
char	*ft_strjoin_without_newline(char *s1, char *s2);

/* mlx_utils_bonus.c */
void	setting_img(t_map *map);
void	setting_img_2(t_map *map, int hei, int wid);
void	put_img(t_map *map, void *w, int x, int y);
void	put_img_c(t_map *map, int w64, int h64);
void	put_img_char(t_map *map, void *ch, int w64, int h64);

/* map_checker_bonus.c */
int		first_line_checker(char *line, t_map *map);
void	middle_line_checker(char *line, int col, t_map *map);
int		last_line_checker(char *line, int col, t_map *map);
int		map_size_checker(int fd, t_map *map);
void	map_checker(t_map *map, char *av);

/* move_w_bonus.c */
void	move_w(t_map *map);
void	move_w2(t_map *map);
void	move_w3(t_map *map, int i);
void	setting_img_w(t_map *map);

/* move_a_bonus.c */
void	move_a(t_map *map);
void	move_a2(t_map *map);
void	move_a3(t_map *map, int i);
void	setting_img_a(t_map *map);

/* move_s_bonus.c */
void	move_s(t_map *map);
void	move_s2(t_map *map);
void	move_s3(t_map *map, int i);
void	setting_img_s(t_map *map);

/* move_d_bonus.c */
void	move_d(t_map *map);
void	move_d2(t_map *map);
void	move_d3(t_map *map, int i);
void	setting_img_d(t_map *map);

/* move_enemy_bonus.c */
void	create_enemy(t_map *map);
void	move_enemy(t_map *map);
void	move_enemy2(t_map *map, int i, int direction);
void	move_enemy_w(t_map *map, int i, int direction);
void	move_enemy_s(t_map *map, int i, int direction);

/* put_char_sprite_img.c */
void	put_img_char_w(t_map *map, int w64, int h64);
void	put_img_char_s(t_map *map, int w64, int h64);
void	put_img_char_a(t_map *map, int w64, int h64);
void	put_img_char_d(t_map *map, int w64, int h64);

/* put_enm_sprite_img.c */
void	put_img_enm(t_map *map, int w64, int h64);
void	put_img_enm_w(t_map *map, int w64, int h64);
void	put_img_enm_s(t_map *map, int w64, int h64);
void	put_img_enm_a(t_map *map, int w64, int h64);
void	put_img_enm_d(t_map *map, int w64, int h64);

#endif
