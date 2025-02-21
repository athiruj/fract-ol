/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:20:11 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/21 15:06:16 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void clear(mlx_t *mlx, mlx_image_t *img)
{
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < HEIGHT; j++)
			mlx_put_pixel(img, i, j, 0x00000000);
}

void	draw_axis(mlx_t *mlx, mlx_image_t *img, double center_x, double	center_y)
{
	clear(mlx, img);
	for	(int n = 0; n < HEIGHT; n++) {
            mlx_put_pixel(img, center_x, n, 0xFFFFFFFF);
            mlx_put_pixel(img, n, center_y, 0xFFFFFFFF);
			if (n % 360 == 0)
			{
				for (int m = 0; m < 10; m++)
				{
            		mlx_put_pixel(img, center_x - m + 5, n, 0xFFFFFFFF);
            		mlx_put_pixel(img, n, center_y - m + 5, 0xFFFFFFFF);
				}
			}
    }
}

void	draw_man(mlx_t *mlx, mlx_image_t *img, double x, double	y)
{
	t_complex tmp;
	t_complex z;

	z.x = 0;
	z.y = 0;
	tmp.x = 0;
	tmp.y = 0;
	clear(mlx, img);
	draw_axis(mlx, img, HEIGHT / 2, HEIGHT / 2);
	for (int i = 0; i < 1000; i++)
	{
		printf("i: %d(%f, %f) %f + %fi\n", i,x, y, z.x * HEIGHT / 4, z.y  * HEIGHT / 4);
		if ((z.x  * HEIGHT / 4) + 360 >= (WIDTH - HEIGHT) 
		&& (z.x  * HEIGHT / 4) + 360 < WIDTH 
		&& (z.y * HEIGHT / 4) + 360 >= 0 
		&& (z.y * HEIGHT / 4) + 360 < HEIGHT)
		{
			mlx_put_pixel(img, (z.x  * HEIGHT / 4) + 360, (z.y * HEIGHT / 4) + 360, 0xFF0000FF);
		}
		tmp.x = (z.x * z.x) - (z.y * z.y) + x;
		tmp.y = (2 * z.x * z.y) + y;
		z = tmp;
	}
}

// void	calculate_mandelbrot(t_fractal *fractal)
// {
// 	int		i;
// 	double	x_temp;

// 	fractal->name = "mandel";
// 	i = 0;
// 	fractal->zx = 0.0;
// 	fractal->zy = 0.0;
// 	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
// 	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
// 	while (++i < fractal->max_iterations)
// 	{
// 		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
// 			+ fractal->cx;
// 		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
// 		fractal->zx = x_temp;
// 		if (fractal->zx * fractal->zx + fractal->zy
// 			* fractal->zy >= __DBL_MAX__)
// 			break ;
// 	}
// 	if (i == fractal->max_iterations)
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
// 	else
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
// 				* i));
// }

void hook_cursor(double xpos, double ypos, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	fract_ol->cursor.x_pos = xpos;
	fract_ol->cursor.y_pos = ypos;
	if (xpos >= (WIDTH - HEIGHT) && xpos < WIDTH && ypos >= 0 && ypos < HEIGHT)
	{
		// draw_axis(fract_ol->mlx, fract_ol->img, fract_ol->cursor.x_pos - (WIDTH - HEIGHT), fract_ol->cursor.y_pos);
		// draw_man(fract_ol->mlx, fract_ol->img, (fract_ol->cursor.x_pos - (WIDTH - HEIGHT) - 360) * 4 / HEIGHT, (-fract_ol->cursor.y_pos + 360) * 4 / HEIGHT);
		// HEIGHT
	}
}