/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:08:45 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/18 05:58:31 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	draw_manual(mlx_image_t **img, mlx_t *mlx, char *fractal)
{
	*img = mlx_new_image(mlx, WIDTH - HEIGHT, HEIGHT);
	if (!*img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	mlx_put_string(mlx, fractal, 5, 5);

	// Delete later
	for	(int y = 0; y < HEIGHT; y++) {
            mlx_put_pixel(*img, WIDTH - HEIGHT - 1, y, 0xFF0000FF);
    }
	return (0);
}
