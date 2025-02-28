/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:20:11 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 04:56:30 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	hook_cursor(double x_pos, double y_pos, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	if (x_pos >= 0 && x_pos < fract_ol->mlx->width
		&& y_pos >= 0 && y_pos < fract_ol->mlx->height)
	{
		if (mlx_is_mouse_down(fract_ol->mlx, MLX_MOUSE_BUTTON_LEFT))
		{
			fract_ol->move.x_offset += (fract_ol->move.x_cursor_pos - x_pos)
				/ fract_ol->move.zoom;
			fract_ol->move.y_offset += (fract_ol->move.y_cursor_pos - y_pos)
				/ fract_ol->move.zoom;
			fract_ol->fractal.fractal_func(
				fract_ol->mlx,
				fract_ol->img,
				&fract_ol->move,
				&fract_ol->complex
			);
		}
		fract_ol->move.x_cursor_pos = x_pos;
		fract_ol->move.y_cursor_pos = y_pos;
		fract_ol->fractal.fractal_func(fract_ol->mlx, fract_ol->img,
			&fract_ol->move, &fract_ol->complex);
	}
}
