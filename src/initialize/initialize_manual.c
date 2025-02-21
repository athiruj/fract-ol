/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_manual.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:45 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/22 00:59:50 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

// int	initialize_manual(mlx_t	*mlx, t_manual **manual, char *name)
// {
// 	*manual = (t_manual *)malloc(sizeof(t_manual));
// 	if (!*manual)
// 	{
// 		perror("Fail to allocate fractal");
// 		return (1);
// 	}
// 	(*manual)->name = name;
// 	(*manual)->img = mlx_new_image(mlx, MANUAL_WIDTH, MANUAL_HEIGHT);
// 	if (!(*manual)->img)
// 	{
// 		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
// 		return (1);
// 	}
// 	if (!ft_strcmp(name, "mandelbrot"))
// 		(*manual)->func = (t_manual_func)manual_mandelbrot;
// 	return (0);
// }
