/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:07 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/21 21:11:33 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
// #include "../src/mlx/mlx.h"

typedef struct s_img
{
	void		*pt;
}	t_img;

typedef struct s_texture
{
	t_img	textures[4];
}	t_texture;

typedef struct s_map
{
	t_texture			*texture;
	void				*mlx;
	void				*win;
	int					f[3];
	int					c[3];

}	t_map;

#endif
