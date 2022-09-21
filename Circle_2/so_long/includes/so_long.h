/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:58:23 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/21 12:36:12 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

/* to mlx */
# include "../mlx/mlx.h"

/* to get_next_line */
# include "../gnl/get_next_line.h"

/* to libft */
# include "../libft/libft.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

typedef struct s_obj
{
	void	*ld;
	void	*tr;
	void	*it;
	void	*d1;
	void	*d2;
	void	*s1;
	void	*s4;
	void	*s7;
	void	*s10;
}				t_obj;

typedef struct s_map
{
	int				x;
	int				y;
	int				row;
	int				col;
	int				all_item;
	int				item_cnt;
	int				walk_cnt;
	char			*map_line;
	void			*mlx;
	void			*win;
	struct s_obj	*obj;
}					t_map;
/* main.c */
int		press_key(int key_code, t_map *map);

/* init.c */
void	obj_init(t_map *map);

/* utils.c */
int		exit_game(t_map *game);
void	print_err(char *message);
char	*ft_strdup_without_newline(char *s);
int		ft_strlcpy_without_newline(char *dst, char *src, int len);
char	*ft_strjoin_without_newline(char *s1, char *s2);

/* mlx_utils.c */
void	setting_img(t_map *map);
void	setting_img_2(t_map *map, int hei, int wid);
void	put_img(t_map *map, void *w, int x, int y);
void	put_img_c(t_map *map, int w64, int h64);
void	put_img_char(t_map *map, void *ch, int w64, int h64);

/* map_checker.c */
int		first_line_checker(char *line, t_map *map);
void	middle_line_checker(char *line, int col, t_map *map);
int		last_line_checker(char *line, int col, t_map *map);
int		map_size_checker(int fd, t_map *map);
void	map_checker(t_map *map, char *av);

/* move_w.c */
void	move_w(t_map *map);
void	setting_img_w(t_map *map);

/* move_a.c */
void	move_a(t_map *map);
void	setting_img_a(t_map *map);

/* move_s.c */
void	move_s(t_map *map);
void	setting_img_s(t_map *map);

/* move_d.c */
void	move_d(t_map *map);
void	setting_img_d(t_map *map);

#endif
