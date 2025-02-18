/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:26:51 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/18 05:46:38 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx, hook_key, fractol);
	mlx_cursor_hook(fractol->mlx, hook_cursor, fractol);
}
