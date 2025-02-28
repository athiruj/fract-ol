/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:54:18 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 04:57:02 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	fract_ol(char **argv);

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
	mlx_image_to_window(fract_ol.mlx, fract_ol.img, 0, 0);
	mlx_loop(fract_ol.mlx);
	mlx_terminate(fract_ol.mlx);
	return (0);
}
