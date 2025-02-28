/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:54:42 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 01:21:20 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

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
#  define WIDTH 720
# endif

# define ITERATION 42
# define ZOOM 1.42
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
typedef struct s_cursor
{
	double	x_pos;
	double	y_pos;
}	t_cursor;

/*
 * @param x_offset is offset x position
 * @param y_offset is offset y position
 * @param zoom
 */
typedef struct s_camera
{
	double	zoom;
	double	x_offset;
	double	y_offset;
	double	iteration;
}	t_camera;

typedef void	(*t_fractal_func)(
							mlx_t *mlx,
							mlx_image_t *img,
							t_camera camera,
							t_cursor cursor
						);

typedef void	(*t_manual)(mlx_t *mlx);

typedef struct s_fractal
{
	char			*name;
	t_manual		manual;
	t_fractal_func	fractal_func;
}	t_fractal;

typedef struct s_fract_ol
{
	t_fractal	fractal;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_camera	camera;
	t_cursor	cursor;

}	t_fract_ol;

int		initialize_fract_ol(t_fract_ol *fract_ol, char **argv);
int		initialize_fractal(t_fractal *fractal, char *name);
int		is_fractal(char *fractal);

void	mandelbrot(
			mlx_t *mlx,
			mlx_image_t *img,
			t_camera camera,
			t_cursor cursor
			);
/* hooks */
void	hooks(t_fract_ol *fract_ol);
void	hook_key(mlx_key_data_t keydata, void *param);
void	hook_cursor(double x_pos, double y_pos, void *param);
void	hook_resize(int32_t width, int32_t height, void *param);
void	hook_scroll(double x, double y, void *param);
void	hook_mouse(
			mouse_key_t button,
			action_t action,
			modifier_key_t mods,
			void *param
			);

/* manual display */
void	manual(mlx_t *mlx, t_fractal *fractal);

void 	draw_axis(mlx_t *mlx, mlx_image_t *img, double center_x, double center_y);
void	paint(mlx_t *mlx, mlx_image_t *img, int width, int height,unsigned int color);
#endif