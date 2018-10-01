/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:34:14 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/01 20:50:19 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	pt(int x, int y, int z)
{
	t_point	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

void	get_max(t_val *tv)
{
	int	x;
	int	y;

	y = 0;
	tv->z_min = tv->tab[0][0];
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

void	afficher(t_val *tv)
{
	int x;
	int y;

	get_max(tv);
	y = 0;
	while (y < tv->nb_y)
	{
		x = 0;
		while (x < tv->nb_x)
		{
			if (x)
				ft_link(pt(x, y, tv->tab[y][x]),
						pt(x - 1, y, tv->tab[y][x - 1]), tv);
			if (y)
				ft_link(pt(x, y, tv->tab[y][x]),
						pt(x, y - 1, tv->tab[y - 1][x]), tv);
			x++;
		}
		y++;
	}
}
