/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:12:52 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/17 05:19:51 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int	draw_manual(mlx_t *mlx, mlx_image_t *img, char *fractal)
{
	mlx_put_string(mlx, "hello", 5, 5);

	return (0);
}

int	initialize_fractol(t_fractol *fractol, char **argv)
{
	fractol->fractal = argv[1];
	fractol->mlx = mlx_init(WIDTH, HEIGHT, argv[1], false);
	if (!fractol->mlx)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	fractol->manual = mlx_new_image(fractol->mlx, WIDTH - HEIGHT, HEIGHT);
	if (!fractol->img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	draw_manual(fractol->mlx, fractol->manual, fractol->fractal);
	
	// Delete later
	for	(int y = 0; y < HEIGHT; y++) {
            mlx_put_pixel(fractol->img, 0, y, 0xFF0000FF);
    }
	return (0);
}
