/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:54:18 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/21 15:02:19 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	fract_ol(char **argv);

void	draw_axis(mlx_t *mlx, mlx_image_t *img, double center_x, double	center_y)
{
	// clear(mlx, img);
	for	(int n = 0; n < mlx->height; n++) {
            mlx_put_pixel(img, center_x, n, 0xFFFFFFFF);
			if (n % 100 == 0)
			{
				for (int m = 0; m < 10; m++)
            		mlx_put_pixel(img, center_x - m + 5, n, 0xFFFFFFFF);
			}
    }
	for	(int n = 0; n < mlx->width; n++) {
            mlx_put_pixel(img, n, center_y, 0xFFFFFFFF);
			if (n % 100 == 0)
			{
				for (int m = 0; m < 10; m++)
            		mlx_put_pixel(img, n, center_y - m + 5, 0xFFFFFFFF);
			}
    }
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !is_fractal(argv[1]))
	{
		ft_putstr_fd("Usage: ./fract_ol <fractal>\n", STDERR_FILENO);
		ft_putstr_fd("Available: fractal\n", STDERR_FILENO);
		ft_putstr_fd("           - mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("           - julia\n", STDERR_FILENO);
		return (1);
	}
	if (fract_ol(argv))
		return (1);
	return (0);
}

int	fract_ol(char **argv)
{
	t_fract_ol		fract_ol;

	if (initialize_fract_ol(&fract_ol, argv))
		return (1);
	hooks(&fract_ol);
	paint(fract_ol.mlx, fract_ol.img, HEIGHT, WIDTH, 0xFF0000FF);
	draw_axis(fract_ol.mlx, fract_ol.img, HEIGHT / 2, HEIGHT / 2);
	mlx_image_to_window(fract_ol.mlx, fract_ol.img, 0, 0);
	mlx_loop(fract_ol.mlx);
	mlx_terminate(fract_ol.mlx);
	return (0);
}
