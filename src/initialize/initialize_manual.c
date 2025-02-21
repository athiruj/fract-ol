/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_manual.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:45 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/21 15:06:16 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

int	initialize_manual(
	mlx_t	*mlx,
	mlx_image_t **img,
	t_fractal **fractal,
	char *name
	)
{
	*img = mlx_new_image(mlx, MANUAL_WIDTH, MANUAL_HEIGHT);
	if (!*img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	if (ft_strcmp(name, "mandelbrot"))
	{
		// (*fractal)->manual = (t_manual_func)manual_mandelbrot;
		printf("in %p\n", (*fractal)->manual);
	}
	return (0);
}
