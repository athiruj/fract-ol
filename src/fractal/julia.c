/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:37:39 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 04:53:43 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

static void	cal_julia(
				mlx_t *mlx,
				mlx_image_t *img,
				t_move *move,
				t_complex *complex
				);

void	julia(
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
			cal_julia(mlx, img, move, complex);
			move->y++;
		}
		move->x++;
		move->y = 0;
	}
}

static void	cal_julia(
			mlx_t *mlx,
			mlx_image_t *img,
			t_move *move,
			t_complex *complex
			)
{
	int		i;
	double	x_temp;

	i = 0;
	complex->x = move->x / move->zoom + move->x_offset;
	complex->y = move->y / move->zoom + move->y_offset;
	complex->cx = sin(move->x_cursor_pos);
	complex->cy = sin(move->y_cursor_pos);
	while (pow(complex->x, 2.0) + pow(complex->y, 2.0) <= (1 << 16)
		&& i < move->iteration)
	{
		x_temp = complex->x;
		complex->x = pow(complex->x, 2.0) - pow(complex->y, 2.0)
			+ complex->cx;
		complex->y = 2 * complex->y * x_temp + complex->cy;
		i++;
	}
	if (i >= move->iteration)
		mlx_put_pixel(img, move->x, move->y, 0x000000FF);
	else
		mlx_put_pixel(img, move->x, move->y, (move->color * (i % 255)));
}
