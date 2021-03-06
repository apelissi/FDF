/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:01:00 by apelissi          #+#    #+#             */
/*   Updated: 2018/10/10 11:42:45 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int keycode, t_val *tv)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == A)
		tv->h = tv->h * 1.1;
	else if (keycode == S)
		tv->h = tv->h / 1.1;
	else if (keycode == Q)
		tv->f = tv->f * 1.1;
	else if (keycode == W)
		tv->f = tv->f / 1.1;
	else if (keycode == Z)
		tv->a = tv->a * 1.1;
	else if (keycode == X && tv->a > 1)
		tv->a = tv->a / 1.1;
	ft_expose_hook(tv);
	return (0);
}
