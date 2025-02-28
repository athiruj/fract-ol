/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:19:09 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 01:49:02 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	hook_mouse(
		mouse_key_t button,
		action_t action,
		modifier_key_t mods,
		void *param
	)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	if (button == MLX_MOUSE_BUTTON_LEFT)
		fract_ol->fractal.fractal_func(
			fract_ol->mlx,
			fract_ol->img,
			&fract_ol->move,
			&fract_ol->complex
		);
}
