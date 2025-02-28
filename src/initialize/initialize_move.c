/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:45 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 03:50:53 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	initialize_move(t_fract_ol *fract_ol)
{
	fract_ol->move.x = 0;
	fract_ol->move.y = 0;
	fract_ol->move.zoom = 200;
	fract_ol->move.x_offset = -2.2;
	fract_ol->move.y_offset = -1.8;
	fract_ol->move.x_cursor_pos = 0;
	fract_ol->move.y_cursor_pos = 0;
	fract_ol->move.iteration = ITERATION;
	fract_ol->move.color = 0xFCBE11FF;
	fract_ol->fractal.fractal_func(
		fract_ol->mlx,
		fract_ol->img,
		&fract_ol->move,
		&fract_ol->complex);
}
