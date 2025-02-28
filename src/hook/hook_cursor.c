/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:20:11 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 01:20:49 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"
// printf("%f + %f, %f + %f\n", fract_ol->camera.x_offset, x_pos - fract_ol->cursor.x_pos, fract_ol->camera.y_offset, y_pos - fract_ol->cursor.y_pos);

void	hook_cursor(double x_pos, double y_pos, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	if (x_pos >= 0 && x_pos < fract_ol->mlx->width
		&& y_pos >= 0 && y_pos < fract_ol->mlx->height)
	{
		if (mlx_is_mouse_down(fract_ol->mlx, MLX_MOUSE_BUTTON_LEFT))
		{
			fract_ol->camera.x_offset += x_pos - fract_ol->cursor.x_pos;
			fract_ol->camera.y_offset += y_pos - fract_ol->cursor.y_pos;
			fract_ol->fractal.fractal_func(
				fract_ol->mlx,
				fract_ol->img,
				fract_ol->camera,
				fract_ol->cursor
			);
			fract_ol->cursor.x_pos = x_pos;
			fract_ol->cursor.y_pos = y_pos;
		}
		else
		{
			fract_ol->cursor.x_pos = x_pos;
			fract_ol->cursor.y_pos = y_pos;
		}
	}
}
