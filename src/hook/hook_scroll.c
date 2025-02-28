/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_scroll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:48:27 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 03:51:21 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	zoom(t_move *move, double x, double y);

void	hook_scroll(double x, double y, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	zoom(&fract_ol->move, x, y);
	fract_ol->fractal.fractal_func(
		fract_ol->mlx,
		fract_ol->img,
		&fract_ol->move,
		&fract_ol->complex
	);
}

void	zoom(t_move *move, double x, double y)
{
	if (y > 0)
	{
		move->x_offset = (x / move->zoom + move->x_offset)
			- (x / (move->zoom * ZOOM));
		move->y_offset = (y / move->zoom + move->y_offset)
			- (y / (move->zoom * ZOOM));
		move->zoom *= ZOOM;
		move->iteration += ZOOM * 0.5;
	}
	else if (y < 0)
	{
		move->x_offset = (x / move->zoom + move->x_offset)
			- (x / (move->zoom / ZOOM));
		move->y_offset = (y / move->zoom + move->y_offset)
			- (y / (move->zoom / ZOOM));
		move->zoom /= ZOOM;
		move->iteration -= ZOOM * 0.5;
	}
}
