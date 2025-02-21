/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:45:56 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/22 01:49:18 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	paint(mlx_t *mlx, mlx_image_t *img, int width, int height,unsigned int color)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			mlx_put_pixel(img, i, j, color);
}

void	mandelbrot(mlx_t *mlx, mlx_image_t *img, t_fract_ol *fract_ol)
{
	paint(mlx, img, mlx->width, mlx->height, 0x1E1E1EFF);
}
