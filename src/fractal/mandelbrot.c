/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:45:56 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 04:45:48 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

static void	cal_mandelbrot(
				mlx_t *mlx,
				mlx_image_t *img,
				t_move *move,
				t_complex *complex
				);

void	mandelbrot(
			mlx_t *mlx,
			mlx_image_t *img,
			t_move *move,
			t_complex *complex
			)
{
	move->x = 0;
	move->y = 0;
	while (move->x < mlx->height)
	{
		while (move->y < mlx->width)
		{
			cal_mandelbrot(mlx, img, move, complex);
			move->y++;
		}
		move->x++;
		move->y = 0;
	}
}

static void	cal_mandelbrot(
			mlx_t *mlx,
			mlx_image_t *img,
			t_move *move,
			t_complex *complex
			)
{
	int		i;
	double	x_temp;

	i = 0;
	complex->x = 0.0;
	complex->y = 0.0;
	complex->cx = (move->x / move->zoom) + move->x_offset;
	complex->cy = (move->y / move->zoom) + move->y_offset;
	while (pow(complex->x, 2.0) + pow(complex->y, 2.0) <= (1 << 16)
		&& i < move->iteration)
	{
		x_temp = pow(complex->x, 2.0) - pow(complex->y, 2.0) + complex->cx;
		complex->y = 2.0 * complex->x * complex->y + complex->cy;
		complex->x = x_temp;
		i++;
	}
	if (i >= move->iteration)
		mlx_put_pixel(img, move->x, move->y, 0x000000FF);
	else
		mlx_put_pixel(img, move->x, move->y, (move->color * i));
}
