/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 15:53:12 by apelissi          #+#    #+#             */
/*   Updated: 2019/01/16 11:52:14 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "fdf.h"

void	same_x(t_point p_a, t_point p_b, t_val *tv)
{
	float	i;
	float	y;
	float	z;

	i = 0;
	while (i <= tv->a)
	{
		z = 0;
		if (tv->nb_z)
			z = (p_a.z + (p_b.z - p_a.z) * (i / tv->a)) * (255 / tv->nb_z);
		y = p_a.y + (p_b.y - p_a.y) * (i / tv->a);
//		mlx_pixel_put(tv->ptr, tv->fen, p_a.x, y, 255 + z * 256 + (255 - z) * 256 * 256);
		set_pixel_img(tv, p_a.x, y, 255 + z * 256 + (255 - z) * 256 * 256);
		i++;
	}
}

void	fil(t_point p_a, t_point p_b, t_val *tv)
{
	float	i;
	float	coef;
	float	k;
	float	x;
	float	z;

	if (p_a.x == p_b.x)
		return (same_x(p_a, p_b, tv));
	i = 0;
	coef = (p_b.y - p_a.y) / (p_b.x - p_a.x);
	k = p_a.y - coef * p_a.x;
	while (i <= tv->a)
	{
		z = 0;
		if (tv->nb_z)
			z = (p_a.z + (p_b.z - p_a.z) * (i / tv->a)) * (255 / tv->nb_z);
		x = p_a.x + (p_b.x - p_a.x) * (i / tv->a);
		if (z >= 0)
		{
		//	mlx_pixel_put(tv->ptr, tv->fen, x, coef * x + k, (255 - z) + (255 - z) * 256 + 255 * 256 * 256);	
			set_pixel_img(tv, x, coef * x + k, (255 - z) + (255 - z) * 256 + 255 * 256 * 256);		
		}
		else
		{
		//	mlx_pixel_put(tv->ptr, tv->fen, x, coef * x + k, 255 + 255 * 256 + (255 + z) * 256 * 256);
			set_pixel_img(tv, x, coef * x + k, 255 + 255 * 256 + (255 + z) * 256 * 256);		
		}
		i++;
	}
}
