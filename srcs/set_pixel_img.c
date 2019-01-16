/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:34:11 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/09 16:51:42 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel_img(t_val *tv, float x, float y, float color)
{
	int i;

	if (x > 0 && x < tv->t_x && y > 0 && y < tv->t_y)
	{
		i = (int)x + (int)y * tv->t_x;
		tv->data[i] = (int)color;
	}
}
