/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:54:42 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/17 05:11:21 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <strings.h>
# include <sys/errno.h>

# include "../submodule/libft/libft.h"
# include "../submodule/get_next_line/get_next_line.h"
# include "../submodule/MLX42/include/MLX42/MLX42.h"

# ifndef HEIGHT
#  define HEIGHT 720
# endif

# ifndef WIDTH
#  define WIDTH 960
# endif

# define ITERATION 42

/*
 * @param x is a real number
 * @param y is a imaginary number
 */
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

/*
 * @param x_offset is offset x position
 * @param y_offset is offset y position
 * @param zoom
 */
typedef struct s_camera
{
	double	x_offset;
	double	y_offset;
	double	zoom;
}	t_camera;

typedef struct s_fractol
{
	char		*fractal;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*manual;
	t_camera	camera;
}	t_fractol;

int	initialize_fractol(t_fractol *fractol, char **argv);

#endif