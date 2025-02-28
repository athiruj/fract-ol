/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fract_ol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:12:52 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 00:53:05 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

int	initialize_fract_ol(t_fract_ol *fract_ol, char **argv)
{
	fract_ol->camera.x_offset = 0;
	fract_ol->camera.y_offset = 0;
	fract_ol->camera.zoom = 0;
	fract_ol->cursor.x_pos = 0;
	fract_ol->cursor.y_pos = 0;
	fract_ol->mlx = mlx_init(WIDTH, HEIGHT, argv[1], true);
	if (!fract_ol->mlx)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	fract_ol->img = mlx_new_image(fract_ol->mlx, WIDTH, HEIGHT);
	if (!fract_ol->img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	if (initialize_fractal(&fract_ol->fractal, argv[1]))
		return (1);
	return (0);
}
