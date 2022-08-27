/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:57:19 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/08/27 14:49:31 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	void	*mlx_img;
	t_image	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "fractol");
	mlx_img = mlx_new_image(mlx_ptr, 1920, 1080);
	mlx_loop(mlx_ptr);
	img.addr = mlx_get_data_addr(mlx_img, &img.bits, &img.size, &img.endian);
}