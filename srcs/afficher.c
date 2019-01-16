/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:34:14 by apelissi          #+#    #+#             */
/*   Updated: 2019/01/15 14:52:56 by apelissi         ###   ########.fr       */
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
