/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:38:25 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 05:03:31 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fract_ol->mlx);
	else if (keydata.key == MLX_KEY_UP)
		fract_ol->move.y_offset -= STEP / fract_ol->move.zoom;
	else if (keydata.key == MLX_KEY_DOWN)
		fract_ol->move.y_offset += STEP / fract_ol->move.zoom;
	else if (keydata.key == MLX_KEY_LEFT)
		fract_ol->move.x_offset -= STEP / fract_ol->move.zoom;
	else if (keydata.key == MLX_KEY_RIGHT)
		fract_ol->move.x_offset += STEP / fract_ol->move.zoom;
	else if (keydata.key == MLX_KEY_R)
		initialize_move(fract_ol);
	else if (keydata.key == MLX_KEY_C)
		fract_ol->move.color += 165813;
	else if (keydata.key == MLX_KEY_Z
		&& fract_ol->move.iteration < MAX_ITERATION)
		fract_ol->move.iteration += 10;
	else if (keydata.key == MLX_KEY_X
		&& fract_ol->move.iteration > MIN_ITERATION)
		fract_ol->move.iteration -= 10;
	fract_ol->fractal.fractal_func(fract_ol->mlx, fract_ol->img,
		&fract_ol->move, &fract_ol->complex);
}
