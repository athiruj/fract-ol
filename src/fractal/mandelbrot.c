/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:45:56 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 00:57:37 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	paint(mlx_t *mlx, mlx_image_t *img, int width, int height,unsigned int color)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			mlx_put_pixel(img, i, j, color);
}

void	mandelbrot(
			mlx_t *mlx,
			mlx_image_t *img,
			t_camera camera,
			t_cursor cursor
			)
{
	// paint(mlx, img, mlx->width, mlx->height, 0xFF0000FF);
	paint(mlx, img, mlx->width, mlx->height, 0xFF0000FF);
	draw_axis(mlx, img, mlx->width / 2 + camera.x_offset,  mlx->height / 2 + camera.y_offset);
}
