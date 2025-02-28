/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:20:40 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/28 10:22:29 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	manual(mlx_t *mlx, t_fractal *fractal)
{
	mlx_put_string(mlx, fractal->name, 5, 5);
}
