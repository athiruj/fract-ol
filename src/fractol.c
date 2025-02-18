/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:54:18 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/18 07:13:11 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	fractol(char **argv);

int	main(int argc, char **argv)
{
	if (argc != 2
		|| (ft_strncmp(argv[1], "mandelbrot", 10)
			&& ft_strncmp(argv[1], "julia", 5)
		))
	{
		ft_putstr_fd("Usage: ./fractol <fractal>\n", STDERR_FILENO);
		ft_putstr_fd("Available: fractal\n", STDERR_FILENO);
		ft_putstr_fd("           - mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("           - julia\n", STDERR_FILENO);
		return (1);
	}
	if (fractol(argv))
		return (1);
	return (0);
}

int	fractol(char **argv)
{
	t_fractol	fractol;

	if (initialize_fractol(&fractol, argv))
		return (1);
	hooks(&fractol);
	draw_manual(&fractol.manual, fractol.mlx, fractol.fractal);
	draw_axis(fractol.mlx, fractol.img, HEIGHT / 2, HEIGHT / 2);
	mlx_image_to_window(fractol.mlx, fractol.manual, 0, 0);
	mlx_image_to_window(fractol.mlx, fractol.img, WIDTH - HEIGHT, 0);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
