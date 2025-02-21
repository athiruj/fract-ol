/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:40:55 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/21 15:06:16 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

int	initialize_fractal(
	mlx_t	*mlx,
	mlx_image_t *img,
	t_fractal *fractal,
	char *name
)
{
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	// if (ft_strcmp(name, "mandelbrot"))
		// fractal->fractal = (t_fractal_func)mandelbrot;	
	return (0);
}
