/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:40:55 by atkaewse          #+#    #+#             */
/*   Updated: 2025/03/01 04:27:33 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

int	initialize_fractal(t_fractal *fractal, char *name)
{
	if (is_fractal(name) == 1)
		*fractal = (t_fractal){.name = name,
			.fractal_func = (t_fractal_func)mandelbrot};
	else if (is_fractal(name) == 2)
		*fractal = (t_fractal){.name = name,
			.fractal_func = (t_fractal_func)julia};
	else
		return (1);
	return (0);
}

/**
 *	@brief check fractal is available
 *	
 *	@param fractal name of fractal
 *  @return - `0` : fractal not available
 *  @return - `1` : Mandelbrot set
 *  @return - `2` : julia set
 */
int	is_fractal(char *fractal)
{
	if (!strcmp(fractal, "mandelbrot"))
		return (1);
	else if (!strcmp(fractal, "julia"))
		return (2);
	else
		return (0);
}
