/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 15:25:13 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/01 20:51:37 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_px(t_point a, t_val *tv)
{
	float	px;

	px = (a.x * tv->f) / (a.y + tv->f);
	px = px * tv->m_x;
	return (px);
}

float	get_py(t_point a, t_val *tv)
{
	float	py;

	py = tv->h + ((a.z - tv->z_min - tv->h) * tv->f) / (a.y + tv->f);
	py = py * tv->m_y;
	py = tv->t_y - py;
	return (py);
}

void	ft_link(t_point a, t_point b, t_val *tv)
{
	float	tmp1;
	float	tmp2;

	tmp1 = get_px(a, tv);
	tmp2 = get_py(a, tv);
	a.x = tmp1;
	a.y = tmp2;
	tmp1 = get_px(b, tv);
	tmp2 = get_py(b, tv);
	b.x = tmp1;
	b.y = tmp2;
	fil(a, b, tv);
}
