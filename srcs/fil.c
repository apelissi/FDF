/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 15:53:12 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/01 20:50:03 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "fdf.h"

int		same_x(t_point p_a, t_point p_b, t_val *tv)
{
	float	i;
	float	y;
	float	z;

	i = 0;
	while (i <= ACC)
	{
		z = 0;
		if (tv->nb_z)
			z = (p_a.z + (p_b.z - p_a.z) * (i / ACC)) * (255 / tv->nb_z);
		y = p_a.y + (p_b.y - p_a.y) * (i / ACC);
		mlx_pixel_put(tv->ptr, tv->fen, p_a.x, y,
				255 + 255 * 256 + (255 - z) * 256 * 256);
		i++;
	}
	return (0);
}

int		same_y(t_point p_a, t_point p_b, t_val *tv)
{
	float	i;
	float	x;
	float	z;

	i = 0;
	while (i <= ACC)
	{
		z = 0;
		if (tv->nb_z)
			z = (p_a.z + (p_b.z - p_a.z) * (i / ACC)) * (255 / tv->nb_z);
		x = p_a.x + (p_b.x - p_a.x) * (i / ACC);
		mlx_pixel_put(tv->ptr, tv->fen, x, p_a.y,
				(255 - z) + 255 * 256 + (255 - z) * 256 * 256);
		i++;
	}
	return (0);
}

int		fil(t_point p_a, t_point p_b, t_val *tv)
{
	float	i;
	float	coef;
	float	k;
	float	x;
	float	z;

	if (p_a.x == p_b.x)
		return (same_x(p_a, p_b, tv));
	else if (p_a.y == p_b.y)
		return (same_y(p_a, p_b, tv));
	coef = (p_b.y - p_a.y) / (p_b.x - p_a.x);
	k = p_a.y - coef * p_a.x;
	i = 0;
	while (i <= ACC)
	{
		z = 0;
		if (tv->nb_z)
			z = (p_a.z + (p_b.z - p_a.z) * (i / ACC)) * (255 / tv->nb_z);
		x = p_a.x + (p_b.x - p_a.x) * (i / ACC);
		mlx_pixel_put(tv->ptr, tv->fen, x, coef * x + k,
				(255 - z) + 255 * 256 + (255 - z) * 256 * 256);
		i++;
	}
	return (0);
}
