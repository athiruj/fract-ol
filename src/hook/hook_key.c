/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:38:25 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 01:01:22 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fract_ol->mlx);
	fract_ol->fractal.fractal_func(
		fract_ol->mlx,
		fract_ol->img,
		fract_ol->camera,
		fract_ol->cursor
	);
}
