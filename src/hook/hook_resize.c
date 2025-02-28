/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:00:46 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 01:48:47 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	hook_resize(int32_t width, int32_t height, void *param)
{
	t_fract_ol	*fract_ol;

	fract_ol = param;
	if (mlx_resize_image(fract_ol->img, width, height) == false)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_close_window(fract_ol->mlx);
	}
	else
	{
		fract_ol->mlx->width = width;
		fract_ol->mlx->height = height;
		fract_ol->fractal.fractal_func(
			fract_ol->mlx,
			fract_ol->img,
			&fract_ol->move,
			&fract_ol->complex
		);
	}
}
