/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_scroll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:48:27 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 00:59:07 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	zoom(t_camera *camera, double x, double y);

void	hook_scroll(double x, double y, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	printf("%lf %lf\n", x, y);
	zoom(&fract_ol->camera, x, y);
	fract_ol->fractal.fractal_func(
		fract_ol->mlx,
		fract_ol->img,
		fract_ol->camera,
		fract_ol->cursor
	);
}

void	zoom(t_camera *camera, double x, double y)
{
	if (y > 0)
	{
		camera->x_offset = (x / camera->zoom + camera->x_offset)
			- (x / (camera->zoom * ZOOM));
		camera->y_offset = (y / camera->zoom + camera->y_offset)
			- (y / (camera->zoom * ZOOM));
		camera->zoom *= ZOOM;
	}
	else if (y < 0)
	{
		camera->x_offset = (x / camera->zoom + camera->x_offset)
			- (x / (camera->zoom / ZOOM));
		camera->y_offset = (y / camera->zoom + camera->y_offset)
			- (y / (camera->zoom / ZOOM));
		camera->zoom /= ZOOM;
	}
}
