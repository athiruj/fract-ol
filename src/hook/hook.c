/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:26:51 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/22 01:01:48 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fract_ol.h"

void	hooks(t_fract_ol *fract_ol)
{
	mlx_key_hook(fract_ol->mlx, hook_key, fract_ol);
	mlx_resize_hook(fract_ol->mlx, hook_resize, fract_ol);
	// mlx_cursor_hook(fract_ol->mlx, hook_cursor, fract_ol);
}
