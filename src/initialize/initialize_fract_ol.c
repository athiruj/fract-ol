/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fract_ol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:12:52 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/21 12:00:55 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

int	initialize_fract_ol(t_fract_ol *fract_ol, char **argv)
{
	fract_ol->fractal = NULL;
	fract_ol->mlx = mlx_init(WIDTH + MANUAL_WIDTH, HEIGHT, argv[1], false);
	if (!fract_ol->mlx)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (1);
	}
	// if (initialize_manual(
	// 		fract_ol->mlx, &fract_ol->manual, &fract_ol->fractal, argv[1])
		// || initialize_fractal(
		// 	fract_ol->mlx, fract_ol->img, fract_ol->fractal, argv[1])
		// )
		// return (1);
	// printf("%p\n", fract_ol->fractal->manual);
		// fract_ol->fractal->manual(fract_ol->mlx, fract_ol->manual);
	// fract_ol->fractal->fractal(fract_ol->mlx, fract_ol->img);
	return (0);
}
