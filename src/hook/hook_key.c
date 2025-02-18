/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:38:25 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/18 05:48:50 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fractol->mlx);
}