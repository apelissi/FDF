/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:16:29 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/08 15:16:32 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_max(t_val *tv)
{
	int	x;
	int	y;

	y = 0;
	while (y < tv->nb_y)
	{
		x = 0;
		while (x < tv->nb_x)
		{
			if (tv->x_max < (x * tv->f) / (y + tv->f))
				tv->x_max = (x * tv->f) / (y + tv->f);
			if (tv->y_max < tv->h + ((tv->tab[y][x] - tv->z_min - tv->h)
						* tv->f) / (y + tv->f))
				tv->y_max = tv->h + ((tv->tab[y][x] - tv->z_min - tv->h)
						* tv->f) / (y + tv->f);
			if (tv->tab[y][x] > tv->nb_z)
				tv->nb_z = tv->tab[y][x];
			x++;
		}
		y++;
	}
	tv->m_x = tv->t_x / tv->x_max;
	tv->m_y = tv->t_y / tv->y_max;
}
