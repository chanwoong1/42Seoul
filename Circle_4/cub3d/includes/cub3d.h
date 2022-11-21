/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:07 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/11/21 15:14:09 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../src/mlx/mlx.h"

typedef struct s_img
{
	void		*pt;
}	t_img;

typedef struct s_texture
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}	t_texture;

typedef struct s_map
{
	t_texture			*texture;
	int					f[3];
	int					c[3];

}	t_map;

#endif
