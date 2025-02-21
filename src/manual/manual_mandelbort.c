/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_mandelbort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:20:40 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/22 02:02:29 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	manual_mandelbrot(mlx_t *mlx, mlx_image_t *img)
{
	// paint(mlx, img, MANUAL_WIDTH, MANUAL_HEIGHT, 0x1E1E1EFF);
	mlx_put_string(mlx, "Mandelbrot set", 5, 5);
}
