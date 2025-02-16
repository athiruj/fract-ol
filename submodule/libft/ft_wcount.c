/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atkaewse <atkaewse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:43:42 by atkaewse          #+#    #+#             */
/*   Updated: 2025/02/16 14:47:08 by atkaewse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcount(const char *s, const char c)
{
	size_t	i;
	int		sta;

	if (!s)
		return (0);
	i = 0;
	sta = 0;
	while (*s)
	{
		if (*s != c && !sta)
		{
			i++;
			sta = 1;
		}
		else if (*s == c && sta)
			sta = 0;
		s++;
	}
	return (i);
}