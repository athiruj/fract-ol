/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:40:55 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/22 02:10:35 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

int	initialize_fractal(
		mlx_t *mlx,
		mlx_image_t *img,
		t_fractal **fractal,
		char *name
	)
{
	*fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!*fractal)
	{
		perror("Fail to allocate fractal");
		return (1);
	}
	(*fractal)->name = name;
	if (!ft_strcmp(name, "mandelbrot"))
	{
		// manual_mandelbrot(mlx, img);
		(*fractal)->fractal_func = (t_fractal_func)mandelbrot;
	}
	return (0);
}
